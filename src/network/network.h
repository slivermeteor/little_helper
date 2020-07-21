#ifndef _INCLUDE_LH_NETWORK_
#define _INCLUDE_LH_NETWORK_

#include <string>
#include <filesystem>

#include "../../include/lh_config.h"

#ifdef LH_WINDOWS_PLATFORM
#include "winhttp.h"

#pragma comment(lib, "winhttp.lib")
#endif // LH_WINDOWS_PLATFORM

namespace little_helper {
namespace network {
    std::string guessFileName(const std::string& url);
    std::wstring guessFileName(const std::wstring& url);

    std::string getUrlParamValue(const std::string& url, const std::string& param);
    std::wstring getUrlParamValue(const std::wstring& url, const std::wstring& param);
    
}
}



#endif // _INCLUDE_LH_NETWORK_
