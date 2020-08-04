#include "little_helper.hpp"

#include <iostream>
#include <string>

using namespace little_helper;

int main()
{
    std::string str_u8 = u8"hello world";
    std::wcout << encoding::from_utf8(str_u8).c_str() << std::endl;

    std::wstring wstr_loc = L"hello world";
    std::cout << encoding::to_utf8(wstr_loc).c_str() << std::endl;

    return 0;
}
