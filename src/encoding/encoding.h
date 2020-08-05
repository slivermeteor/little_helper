#ifndef _INCLUDE_LH_ENCODING_
#define _INCLUDE_LH_ENCODING_

#include "include/lh_config.h"

#include <codecvt>
#include <string>
#include <cstring>


namespace little_helper {
namespace encoding {

std::string to_utf8(const std::wstring& src);
std::string to_utf8(const wchar_t* src, int size = -1);

std::wstring from_utf8(const std::string& src);
std::wstring from_utf8(const char* src, int size = -1);

std::string to_local(const std::wstring& src);
std::string to_local(const wchar_t* src, int size = -1);

std::wstring from_local(const std::string& src);
std::wstring from_local(const char* src, int size = -1);



}
}


#endif // _INCLUDE_LH_ENCODING_
