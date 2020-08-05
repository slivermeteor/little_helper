#include "encoding.h"
#ifdef PLATFORM_WINDOWS_IN_LH
#include <Windows.h>
#endif

using namespace little_helper;

std::string encoding::to_utf8(const std::wstring& src)
{
    return to_utf8(src.c_str(), src.size());
}

std::string encoding::to_utf8(const wchar_t* src, int size)
{
    std::string str_u8(size, '\0');
    if (size < 0)
        size = static_cast<int>(wcslen(src));
        
#ifdef PLATFORM_WINDOWS_IN_LH
    int need_size = WideCharToMultiByte(CP_UTF8, 0, src, size, nullptr, 0, nullptr, false);
    str_u8.resize(need_size);
    WideCharToMultiByte(CP_UTF8, 0, src, size, const_cast<char*>(str_u8.c_str()), need_size, nullptr, false);
#else
    auto& f = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(std::locale());
    std::mbstate_t state = std::mbstate_t();
    const wchar_t* from_next = nullptr;
    char* to_next = nullptr;
    f.out(state, src, src + size, from_next, const_cast<char*>(str_u8.c_str()), const_cast<char*>(str_u8.c_str()) + str_u8.length(), to_next);
    str_u8.resize(to_next - str_u8.c_str());
#endif // PLATFORM_WINDOWS_IN_LH
    return str_u8;
}

std::wstring encoding::from_utf8(const std::string& src)
{
    return from_utf8(src.c_str(), src.size());
}

std::wstring encoding::from_utf8(const char* src, int size)
{
    std::wstring wstr_u8(size, L'\0');
    if (size < 0)
        size = static_cast<int>(strlen(src));

#ifdef PLATFORM_WINDOWS_IN_LH
    int need_size = MultiByteToWideChar(CP_UTF8, 0, src, size, 0, 0);
    wstr_u8.resize(need_size);
    MultiByteToWideChar(CP_UTF8, 0, src, size, const_cast<wchar_t*>(wstr_u8.c_str()), need_size);
#else
    auto&& f = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(std::locale());
    std::mbstate_t state = std::mbstate_t();
    const char* from_next = nullptr;
    wchar_t* to_next = nullptr;
    f.in(state, src, src + size, from_next, const_cast<wchar_t*>(wstr_u8.c_str()), const_cast<wchar_t*>(wstr_u8.c_str()) + wstr_u8.length(), to_next);
    wstr_u8.resize(to_next - const_cast<wchar_t*>(wstr_u8.c_str()));
#endif // PLATFORM_WINDOWS_IN_LH
    return wstr_u8;
}
