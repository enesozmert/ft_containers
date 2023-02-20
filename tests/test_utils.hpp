#pragma once

#include "../inc/containers/vector.hpp"

template <typename T>
void printVec(ft::vector<T> vec)
{
    std::cout << "size" << vec.size() << std::endl;
    std::cout << "cap" << vec.capacity() << std::endl; // 2 4 8 16
    std::cout << "vec contains:";
    for (unsigned i = 0; i < vec.size(); ++i)
        std::cout << ' ' << vec[i];
    std::cout << '\n';
}
void test_print(std::string name, std::string processName)
{
    if (processName.find("OK") != std::string::npos)
    {
        std::cout << "\033[35m" << name << "\033[0m"
                  << "/"
                  << "\033[1;32m" << processName << "\033[0m" << std::endl;
    }
    else if (processName.find("FAIL") != std::string::npos)
    {
        std::cout << "\033[35m" << name << "\033[0m"
                  << "/"
                  << "\033[1;31m" << processName << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[35m" << name << "\033[0m"
                  << "/" << processName << std::endl;
}