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
    
    
}
}



#endif // _INCLUDE_LH_NETWORK_
