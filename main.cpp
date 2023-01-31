#include <iostream>
#include "./inc/containers/Vector.hpp"

using namespace ft;
int main()
{
    ft::Vector<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    std::cout << "Size : " << ar.size() << std::endl;
    // for (int i;i < ar.size() ; ptr++)
    //     cout << *ptr << " ";
      
    return 0;    
}