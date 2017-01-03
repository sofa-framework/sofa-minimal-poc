/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2016 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU General Public License as published by the Free  *
* Software Foundation; either version 2 of the License, or (at your option)   *
* any later version.                                                          *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    *
* more details.                                                               *
*                                                                             *
* You should have received a copy of the GNU General Public License along     *
* with this program; if not, write to the Free Software Foundation, Inc., 51  *
* Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.                   *
*******************************************************************************
*                            SOFA :: Applications                             *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <sstream>
using std::ostringstream ;
#include <fstream>

#include <string>
using std::string;

#include <vector>
using std::vector;


#include <sofa/helper/ArgumentParser.h>
#include <SofaSimulationCommon/common.h>
#include <sofa/simulation/Node.h>
#include <sofa/helper/system/PluginManager.h>
#include <sofa/simulation/config.h> // #defines SOFA_HAVE_DAG (or not)
#include <SofaSimulationCommon/init.h>
#ifdef SOFA_HAVE_DAG
#include <SofaSimulationGraph/init.h>
#include <SofaSimulationGraph/DAGSimulation.h>
#endif
#include <SofaSimulationTree/init.h>
#include <SofaSimulationTree/TreeSimulation.h>
using sofa::simulation::Node;

#include <sofa/helper/Factory.h>
#include <sofa/helper/cast.h>
#include <sofa/helper/BackTrace.h>
#include <sofa/helper/system/FileRepository.h>
#include <sofa/helper/system/SetDirectory.h>
#include <sofa/helper/Utils.h>
#include "BatchGUI.h"
#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/gl.h>
#include <sofa/helper/system/atomic.h>

using sofa::core::ExecParams ;

#include <sofa/helper/system/console.h>
using sofa::helper::Utils;
using sofa::helper::Console;

using sofa::simulation::tree::TreeSimulation;
using sofa::simulation::graph::DAGSimulation;
using sofa::helper::system::SetDirectory;
using sofa::core::objectmodel::BaseNode ;

#include <sofa/helper/logging/Messaging.h>

#ifdef SOFA_SMP
#include <athapascan-1>
#endif /* SOFA_SMP */
#ifdef WIN32
#include <windows.h>
#endif

using sofa::helper::system::DataRepository;
using sofa::helper::system::PluginRepository;
using sofa::helper::system::PluginManager;

#include <sofa/helper/logging/MessageDispatcher.h>
using sofa::helper::logging::MessageDispatcher ;

#include <sofa/helper/logging/ClangMessageHandler.h>
using sofa::helper::logging::ClangMessageHandler ;

#include <sofa/helper/logging/ExceptionMessageHandler.h>
using sofa::helper::logging::ExceptionMessageHandler;

// ---------------------------------------------------------------------
// ---
// ---------------------------------------------------------------------
int main(int argc, char** argv)
{
    sofa::helper::BackTrace::autodump();

    ExecParams::defaultInstance()->setAspectID(0);

#ifdef WIN32
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD s;
        s.X = 160; s.Y = 10000;
        SetConsoleScreenBufferSize(hStdout, s);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(hStdout, &csbi))
        {
            SMALL_RECT winfo;
            winfo = csbi.srWindow;
            //winfo.Top = 0;
            winfo.Left = 0;
            //winfo.Bottom = csbi.dwSize.Y-1;
            winfo.Right = csbi.dwMaximumWindowSize.X-1;
            SetConsoleWindowInfo(hStdout, TRUE, &winfo);
        }

    }
#endif

    string fileName ;
    bool        startAnim = false;
    bool        printFactory = true;
    bool        loadRecent = false;
    bool        temporaryFile = false;
    bool        testMode = false;
    int         nbIterations = sofa::gui::BatchGUI::DEFAULT_NUMBER_OF_ITERATIONS;
    unsigned int nbMSSASamples = 1;
    unsigned    computationTimeSampling=0; ///< Frequency of display of the computation time statistics, in number of animation steps. 0 means never.

    string gui = "";
    string verif = "";
#ifdef SOFA_SMP
    string simulationType = "smp";
#elif defined(SOFA_HAVE_DAG)
    string simulationType = "dag";
#else
    string simulationType = "tree";
#endif
    vector<string> plugins;
    vector<string> files;
#ifdef SOFA_SMP
    string nProcs="";
    bool        disableStealing = false;
    bool        affinity = false;
#endif
    string colorsStatus = "auto";

    string gui_help = "choose the UI (";
    gui_help += "batch";
    gui_help += ")";

    sofa::helper::parse(&files, "This is a SOFA application. Here are the command line arguments")
    // alphabetical order on short name
    .option(&startAnim,'a',"start","start the animation loop")
    .option(&computationTimeSampling,'c',"computationTimeSampling","Frequency of display of the computation time statistics, in number of animation steps. 0 means never.")
    .option(&gui,'g',"gui",gui_help.c_str())
    .option(&plugins,'l',"load","load given plugins")
    .option(&nbMSSASamples, 'm', "msaa", "number of samples for MSAA (Multi Sampling Anti Aliasing ; value < 2 means disabled")
    .option(&nbIterations,'n',"nb_iterations","(only batch) Number of iterations of the simulation")
    .option(&printFactory,'p',"factory","print factory logs")
    .option(&loadRecent,'r',"recent","load most recently opened file")
    .option(&simulationType,'s',"simu","select the type of simulation (bgl, dag, tree, smp)")
    .option(&temporaryFile,'t',"temporary","the loaded scene won't appear in history of opened files")
    .option(&testMode,'x',"test","select test mode with xml output after N iteration")
    .option(&verif,'v',"verification","load verification data for the scene")
    .option(&colorsStatus,'z',"colors","use colors on stdout and stderr (yes, no, auto, clang, test)")
    (argc,argv);

    // TODO: create additionnal message handlers depending on command-line parameters

    // Note that initializations must be done after ArgumentParser that can exit the application (without cleanup)
    // even if everything is ok e.g. asking for help
    sofa::simulation::tree::init();
#ifdef SOFA_HAVE_DAG
    sofa::simulation::graph::init();
#endif
//    sofa::component::initComponentBase();


#ifdef SOFA_HAVE_DAG
    if (simulationType == "tree")
        sofa::simulation::setSimulation(new TreeSimulation());
    else
        sofa::simulation::setSimulation(new DAGSimulation());
#else //SOFA_HAVE_DAG
    sofa::simulation::setSimulation(new TreeSimulation());
#endif


    if (colorsStatus == "auto")
        Console::setColorsStatus(Console::ColorsAuto);
    else if (colorsStatus == "yes")
        Console::setColorsStatus(Console::ColorsEnabled);
    else if (colorsStatus == "no")
        Console::setColorsStatus(Console::ColorsDisabled);
    else if (colorsStatus == "clang"){
        MessageDispatcher::clearHandlers() ;
        MessageDispatcher::addHandler( new ClangMessageHandler() ) ;
    }
    else if (colorsStatus == "test"){
        MessageDispatcher::addHandler( new ExceptionMessageHandler() ) ;
    }
    else{
        Console::setColorsStatus(Console::ColorsAuto);
        msg_warning("") << "Invalid argument ‘" << colorsStatus << "‘ for ‘--colors‘";
    }

    // Add the plugin directory to PluginRepository
#ifdef WIN32
    const string pluginDir = Utils::getExecutableDirectory();
#else
    const string pluginDir = Utils::getSofaPathPrefix() + "/lib";
#endif
    PluginRepository.addFirstPath(pluginDir);

    if (!files.empty())
        fileName = files[0];

    plugins.push_back("SofaNG");
    for (unsigned int i=0; i<plugins.size(); i++)
        PluginManager::getInstance().loadPlugin(plugins[i]);

    // to force loading plugin SofaPython if existing
    {
        std::ostringstream no_error_message; // no to get an error on the console if SofaPython does not exist
        sofa::helper::system::PluginManager::getInstance().loadPlugin("SofaPython",&no_error_message);
    }

    PluginManager::getInstance().init();
    sofa::gui::BatchGUI* batchgui = NULL;
    std::vector<std::string> opts;
    if(gui.compare("batch") == 0 && nbIterations >= 0)
    {
        ostringstream oss ;
        oss << "nbIterations=";
        oss << nbIterations;
        opts.push_back(oss.str());
        batchgui = sofa::gui::BatchGUI::CreateGUI("runSofaNG_batch", opts );
    }

    if (int err = batchgui->InitGUI(argv[0],opts))
        return err;

    if (fileName.empty())
    {
        fileName = "Demos/caduceus.scn";

        fileName = DataRepository.getFile(fileName);
    }

    Node::SPtr groot = sofa::simulation::getSimulation()->load(fileName.c_str());
    if( !groot )
        groot = sofa::simulation::getSimulation()->createNewGraph("");
    sofa::core::ObjectFactory::getInstance()->dump()  ;
    sofa::simulation::getSimulation()->init(groot.get());
    batchgui->setScene(groot,fileName.c_str(), temporaryFile);

    //=======================================
    //Apply Options

    if (startAnim)
        groot->setAnimate(true);
    if (true)
    {
        msg_info("") << "////////// FACTORY //////////" ;
        sofa::helper::printFactoryLog();
        msg_info("") << "//////// END FACTORY ////////" ;
    }

    if( computationTimeSampling>0 )
    {
        sofa::helper::AdvancedTimer::setEnabled("Animate", true);
        sofa::helper::AdvancedTimer::setInterval("Animate", computationTimeSampling);
    }

    //=======================================
    // Run the main loop
    if (int err = batchgui->mainLoop())
        return err;
    groot = dynamic_cast<Node*>( batchgui->currentSimulation() );

    if (groot!=NULL)
        sofa::simulation::getSimulation()->unload(groot);


    batchgui->closeGUI();

    sofa::simulation::common::cleanup();
    sofa::simulation::tree::cleanup();
#ifdef SOFA_HAVE_DAG
    sofa::simulation::graph::cleanup();
#endif
    return 0;
}
