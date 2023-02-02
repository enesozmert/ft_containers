#include <iostream>
#include <vector>
#include "./inc/containers/Vector.hpp"

using namespace ft;
int main()
{
    ft::Vector<int> ar;
    std::vector<int> oar;

    ar.push_back(1);
    ar.push_back(2);
    std::cout << "Size : " << ar.size() << std::endl;
    for (size_t i = 0; i < ar.size(); i++)
    {
        std::cout << ar[i] << "-";
    }
    std::cout << "" << std::endl;
    std::cout << "End Of My Vector" << std::endl;
    ar.pop_back();
    std::cout << "Size : " << ar.size() << std::endl;
    for (size_t i = 0; i < ar.size(); i++)
    {
        std::cout << ar[i] << "-";
    }
    std::cout << "" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Start Real Vector" << std::endl;
    oar.push_back(1);
    oar.push_back(2);
    std::cout << "Size : " << oar.size() << std::endl;
    for (size_t i = 0; i < oar.size(); i++)
    {
        std::cout << oar[i] << "-";
    }
    std::cout << "" << std::endl;
    std::cout << "Cap : " << oar.capacity() << std::endl;
    oar.pop_back();
    std::cout << "Size : " << oar.size() << std::endl;
    for (size_t i = 0; i < oar.size(); i++)
    {
        std::cout << oar[i] << "-";
    }
    std::cout << "" << std::endl;
    std::cout << "Cap : " << oar.capacity() << std::endl;


    // for (int i;i < ar.size() ; ptr++)
    //     cout << *ptr << " ";
      
    return 0;    
}