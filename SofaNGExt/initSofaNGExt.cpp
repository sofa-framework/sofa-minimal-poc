#include "sofangext.h"

#include <cstring>
#include <string>

namespace sofa
{

namespace component
{

extern "C" {
    SOFA_SOFANGEXT_API void initExternalModule();
    SOFA_SOFANGEXT_API const char* getModuleName();
    SOFA_SOFANGEXT_API const char* getModuleVersion();
    SOFA_SOFANGEXT_API const char* getModuleLicense();
    SOFA_SOFANGEXT_API const char* getModuleDescription();
    SOFA_SOFANGEXT_API const char* getModuleComponentList();
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
    return "SofaNGExt";
}

const char* getModuleVersion()
{
	return "beta 1.0";
}

const char* getModuleDescription()
{
    return "Sofa Next Gen Ext";
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

