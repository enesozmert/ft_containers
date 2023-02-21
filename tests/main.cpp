#include <iostream>
#include <vector>
#include "test.hpp"
#include "../inc/containers/vector.hpp"

using namespace ft;




int main()
{
    // ft::Vector<int> ar;
    // std::vector<int> oar;

    // ar.push_back(1);
    // ar.push_back(2);
    // std::cout << "Size : " << ar.size() << std::endl;
    // for (size_t i = 0; i < ar.size(); i++)
    // {
    //     std::cout << ar[i] << "-";
    // }
    // std::cout << "" << std::endl;
    // std::cout << "End Of My Vector" << std::endl;
    // ar.pop_back();
    // std::cout << "Size : " << ar.size() << std::endl;
    // for (size_t i = 0; i < ar.size(); i++)
    // {
    //     std::cout << ar[i] << "-";
    // }
    // std::cout << "" << std::endl;
    // std::cout << "-----------------------------------------" << std::endl;
    // std::cout << "Start Real Vector" << std::endl;
    // oar.push_back(1);
    // oar.push_back(2);
    // std::cout << "Size : " << oar.size() << std::endl;
    // for (size_t i = 0; i < oar.size(); i++)
    // {
    //     std::cout << oar[i] << "-";
    // }
    // std::cout << "" << std::endl;
    // std::cout << "Cap : " << oar.capacity() << std::endl;
    // oar.pop_back();
    // std::cout << "Size : " << oar.size() << std::endl;
    // for (size_t i = 0; i < oar.size(); i++)
    // {
    //     std::cout << oar[i] << "-";
    // }
    // std::cout << "" << std::endl;
    // std::cout << "Cap : " << oar.capacity() << std::endl;

    // // set some initial content:
    // for (int i = 1; i < 10; i++)
    //     ar.push_back(i);

    // ar.resize(5);
    // ar.resize(8, 100);
    // ar.resize(12);

    // std::cout << "myvector contains resize test:";
    // for (size_t i = 0; i < ar.size(); i++)
    //     std::cout << ' ' << ar[i];
    // std::cout << '\n';
    // // for (int i;i < ar.size() ; ptr++)
    // //     cout << *ptr << " ";
    // std::cout << "-----------------------------------------" << std::endl;
    // ft::Vector<int>::size_type sz;

    // ft::Vector<int> foo;
    // sz = foo.capacity();
    // std::cout << "making foo grow:\n";
    // for (int i = 0; i < 100; ++i)
    // {
    //     foo.push_back(i);
    //     if (sz != foo.capacity())
    //     {
    //         sz = foo.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }

    // ft::Vector<int> bar;
    // sz = bar.capacity();
    // bar.reserve(100); // this is the only difference with foo above
    // std::cout << "making bar grow:\n";
    // for (int i = 0; i < 100; ++i)
    // {
    //     bar.push_back(i);
    //     if (sz != bar.capacity())
    //     {
    //         sz = bar.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }
    // std::cout << "-----------------------------------------" << std::endl;
    // std::cout << std::boolalpha;
    // ft::Vector<int> numbers;
    // std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    // numbers.push_back(42);
    // std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
    // std::cout << "-----------------------------------------" << std::endl;
    // ft::vector<int> foo1(3, 100); // three ints with a value of 100
    // ft::vector<int> bar1(5, 200); // five ints with a value of 200

    // foo1.swap(bar1);

    // std::cout << "foo contains:";
    // for (unsigned i = 0; i < foo1.size(); i++)
    //     std::cout << ' ' << foo1[i];
    // std::cout << '\n';

    // std::cout << "bar contains:";
    // for (unsigned i = 0; i < bar1.size(); i++)
    //     std::cout << ' ' << bar1[i];
    // std::cout << '\n';
    // std::cout << "-----------------------------------------" << std::endl;
    // std::vector<int> myvector;

    // myvector.push_back(78);
    // myvector.push_back(16);

    // std::cout << "myvector.front() is now " << myvector.front() << '\n';

    // ft::vector<int> myvector;
    // myvector.push_back(3);
    // myvector.push_back(4);
    // myvector.push_back(1);
    // myvector.push_back(7);
    // myvector.push_back(3);
    // std::cout << myvector.at(300);

    // std::vector<int> orvector;
    // orvector.push_back(3);
    // orvector.push_back(4);
    // orvector.push_back(1);
    // orvector.push_back(7);
    // orvector.push_back(3);
    // std::cout << orvector.at(300);

    // ft::vector<int> ar;
    // ft::vector<int>::iterator ptr;

    // ar.push_back(1);
    // ar.push_back(2);
    // ar.push_back(3);
    // ar.push_back(4);

    // std::cout << "The vector elements are : ";
    // for (ptr = ar.begin(); ptr < ar.end(); ptr++)
    //     std::cout << *ptr << " ";

    // std::vector<int> v;
    // ft::vector<std::string> x;
    // ft::vector<std::string>::iterator ptr;
    // ft::vector<std::string>::iterator ptr1;
    // v.assign(7, 100);
    // x.assign(8, "200");

    // ptr = x.begin();
    // ptr1 = x.end() - 7;
    // std::cout << "Size of first: " << int(v.size()) << '\n';

    // std::cout << "Elements are\n";
    // for (size_t i = 0; i < x.size(); i++)
    //     std::cout << x[i] << std::endl;

    // // modify the elements
    // x.assign(ptr, ptr1);

    // std::cout << "\nModified VectorElements are\n";
    // for (size_t i = 0; i < x.size(); i++)
    //     std::cout << x[i] << std::endl;

    // std::vector<int> v;
    // v.assign(7, 100);

    // std::cout << "Size of first: "
    //           << int(v.size()) << '\n';

    // std::cout << "Elements are\n";
    // for (size_t i = 0; i < v.size(); i++)
    //     std::cout << v[i] << std::endl;

    // std::cout << "-----------------------------------------" << std::endl;

    /*     ft::vector<int> myv;
        myv.assign(7, 100);

        std::cout << "My Size of first: "
                  << int(myv.size()) << '\n';

        std::cout << "cpa" << myv.capacity() << std::endl;

        std::cout << "My Elements are\n";
        for (size_t i = 0; i < myv.size(); i++)
            std::cout << myv[i] << std::endl; */

    // ft::vector<int> myv;
    // myv.push_back(7);
    // myv.push_back(71);
    // myv.push_back(72);
    // std::cout << "begin : " << *myv.begin() << std::endl;
    // std::cout << "end : " << *myv.end() << std::endl;
    // myv.assign(myv.begin(),myv.end());
    // std::cout << "Elements are\n";
    // for (size_t i = 0; i < myv.size(); i++)
    //     std::cout << myv[i] << std::endl;
    // std::cout << "-----------------------------------------" << std::endl;



    // set some values (from 1 to 10)
    // for (int i = 1; i <= 10; i++)
    //     myvector.push_back(i);
    // printVec(myvector);

    // erase the 6th element
    // myvector.erase(myvector.begin() + 5);
    // printVec(myvector);
    // std::cout << "-------------------[BEGIN-END)---------------------" << std::endl;
    // erase the first 3 elements:
    // myvector.erase(myvector.begin() + 1, myvector.begin() + 5); //[first, last) 1, 2, 0 10
    // printVec(myvector);
    test_all();
    // ft:vector<int> vector1;
    // vector1.push_back(1);
    // vector1.push_back(2);

    // ft::vector<int>::const_iterator const_iterator1;
    // const_iterator1 = vector1.begin();
    // return (0);
}
