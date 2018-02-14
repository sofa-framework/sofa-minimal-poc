#include "sofaminimal0.h"

#include <cstring>
#include <string>

namespace sofa
{

namespace component
{

extern "C" {
    SOFA_SOFAMINIMAL_API void initExternalModule();
    SOFA_SOFAMINIMAL_API const char* getModuleName();
    SOFA_SOFAMINIMAL_API const char* getModuleVersion();
    SOFA_SOFAMINIMAL_API const char* getModuleLicense();
    SOFA_SOFAMINIMAL_API const char* getModuleDescription();
    SOFA_SOFAMINIMAL_API const char* getModuleComponentList();
}

void initExternalModule()
{
	static bool first = true;
	if (first)
	{
		first = false;
	}
}

const char* getModuleName()
{
    return "SofaMinimal0";
}

const char* getModuleVersion()
{
	return "beta 1.0";
}

const char* getModuleDescription()
{
    return "Sofa Next Gen";
}

const char* getModuleComponentList()
{
	std::string commonentlist;

    commonentlist += "";
	commonentlist += "";

	return commonentlist.c_str();
}
const char* getModuleLicense()
{
    return "MIMESIS(c)";
}

SOFA_LINK_CLASS(MechanicalObject)


} // namespace component

} // namespace sofa

