#include "little_helper.hpp"

#include <iostream>
#include <string>

using namespace little_helper;

int main()
{
    std::string str_u8 = u8"hello world";
    // std::wstring wstr_u8 = encoding::from_utf8(str_u8);

    // std::wcout << wstr_u8 << std::endl;

    std::cout << str_u8 << std::endl;
    return 0;
}
