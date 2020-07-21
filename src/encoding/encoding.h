#ifndef _INCLUDE_LH_ENCODING_
#define _INCLUDE_LH_ENCODING_

#include "../../include/lh_config.h"

#include <codecvt>
#include <string>


namespace little_helper {
namespace encoding {

std::string to_utf8(const std::wstring& src);
std::string to_utf8(const wchar_t* src, int size = -1);

}
}


#endif // _INCLUDE_LH_ENCODING_
