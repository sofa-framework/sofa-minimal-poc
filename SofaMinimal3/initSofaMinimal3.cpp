#include "sofaminimal3.h"

#include <cstring>
#include <string>

namespace sofa
{

namespace component
{

extern "C" {
    SOFA_SOFAMINIMAL3_API void initExternalModule();
    SOFA_SOFAMINIMAL3_API const char* getModuleName();
    SOFA_SOFAMINIMAL3_API const char* getModuleVersion();
    SOFA_SOFAMINIMAL3_API const char* getModuleLicense();
    SOFA_SOFAMINIMAL3_API const char* getModuleDescription();
    SOFA_SOFAMINIMAL3_API const char* getModuleComponentList();
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
    return "SofaMinimal3";
}

const char* getModuleVersion()
{
	return "beta 1.0";
}

const char* getModuleDescription()
{
    return "Sofa Minimal 3";
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


} // namespace component

} // namespace sofa

