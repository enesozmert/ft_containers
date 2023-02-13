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

    // set some initial content:
    for (int i = 1; i < 10; i++)
        ar.push_back(i);

    ar.resize(5);
    ar.resize(8, 100);
    ar.resize(12);

    std::cout << "myvector contains resize test:";
    for (size_t i = 0; i < ar.size(); i++)
        std::cout << ' ' << ar[i];
    std::cout << '\n';
    // for (int i;i < ar.size() ; ptr++)
    //     cout << *ptr << " ";
    std::cout << "-----------------------------------------" << std::endl;
    ft::Vector<int>::size_type sz;

    ft::Vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    ft::Vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100); // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        bar.push_back(i);
        if (sz != bar.capacity())
        {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::boolalpha;
    ft::Vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "-----------------------------------------" << std::endl;
    ft::Vector<int> foo1(3, 100); // three ints with a value of 100
    ft::Vector<int> bar1(5, 200); // five ints with a value of 200

    foo1.swap(bar1);

    std::cout << "foo contains:";
    for (unsigned i = 0; i < foo1.size(); i++)
        std::cout << ' ' << foo1[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i = 0; i < bar1.size(); i++)
        std::cout << ' ' << bar1[i];
    std::cout << '\n';
    std::cout << "-----------------------------------------" << std::endl;
    std::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    std::cout << "myvector.front() is now " << myvector.front() << '\n';
    return 0;
}