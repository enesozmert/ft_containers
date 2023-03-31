#include <iostream>
#include <vector>
#include <map>
#include "test.hpp"
#include "../inc/containers/vector.hpp"
#include "../inc/containers/map.hpp"
#include "../inc/tree/RBTree.hpp"
#include "../inc/tree/RBTreeNode.hpp"
#include "test_map.hpp"

using namespace ft;

// void print_my_vector(ft::vector<int> v)
// {
//     ft::vector<int>::iterator it = v.begin();
//     std::cout << "print MY vector";
//     std::cout << "\n-------------\n";
//     std::cout << "capacity: " << v.capacity() << " size: " << v.size() << std::endl;

//     std::cout << "datas ---> ";
//     while (it != v.end())
//         std::cout << *it++ << " ";
//     std::cout << "\n-------------\n";
// }

// void print_orj_vector(std::vector<int> v)
// {
//     std::vector<int>::iterator it = v.begin();
//     std::cout << "print ORJ vector";
//     std::cout << "\n-------------\n";
//     std::cout << "capacity: " << v.capacity() << " size: " << v.size() << std::endl;

//     std::cout << "datas ---> ";
//     while (it != v.end())
//         std::cout << *it++ << " ";
//     std::cout << "\n-------------\n";
// }

// int main()
// {
// // ft::vector<int> myVecInsert;
// //     std::vector<int> orjVecInsert;

//     // myVecInsert.push_back(1);
//     // myVecInsert.push_back(2);
//     // myVecInsert.push_back(3);
//     // print_my_vector(myVecInsert);

//     // orjVecInsert.push_back(1);
//     // orjVecInsert.push_back(2);
//     // orjVecInsert.push_back(3);
//     // print_orj_vector(orjVecInsert);

//     // std::cout<<"insertion starting~~~~~~~~>";
//     // myVecInsert.insert(myVecInsert.begin(), -1);
//     // print_my_vector(myVecInsert);
//     // orjVecInsert.insert(orjVecInsert.begin(), -1);
//     // print_orj_vector(orjVecInsert);

//     // std::cout<<"insertion starting~~~~~~~~>";
//     // myVecInsert.insert(myVecInsert.begin(), -1);
//     // print_my_vector(myVecInsert);
//     // orjVecInsert.insert(orjVecInsert.begin(), -1);
//     // print_orj_vector(orjVecInsert);

//     // std::cout<<"insertion starting~~~~~~~~>";
//     // myVecInsert.insert(myVecInsert.begin() + 2, 200);
//     // print_my_vector(myVecInsert);
//     // orjVecInsert.insert(orjVecInsert.begin() + 2, 200);
//     // print_orj_vector(orjVecInsert);

//     // myVecInsert.insert(myVecInsert.end(), 400);
//     // print_my_vector(myVecInsert);
//     // orjVecInsert.insert(orjVecInsert.end(), 400);
//     // print_orj_vector(orjVecInsert);

//     // std::cout<<"insertion starting~~~~~~~~>";
//     // myVecInsert.insert(myVecInsert.begin() + 2, 5, 200);
//     // print_my_vector(myVecInsert);
//     // orjVecInsert.insert(orjVecInsert.begin() + 2, 5, 200);
//     // print_orj_vector(orjVecInsert);

//         ft::vector<int> myVecInsert;
//     std::vector<int> orjVecInsert;

//     myVecInsert.insert(myVecInsert.begin(), 0);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin(), 0);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.push_back(1);
//     myVecInsert.push_back(2);
//     myVecInsert.push_back(3);
//     print_my_vector(myVecInsert);

//     orjVecInsert.push_back(1);
//     orjVecInsert.push_back(2);
//     orjVecInsert.push_back(3);
//     print_orj_vector(orjVecInsert);

//     std::cout<<"insertion starting~~~~~~~~>";
//     myVecInsert.insert(myVecInsert.begin(), -1);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin(), -1);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.begin() + 2, 200);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin() + 2, 200);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.end(), 5);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.end(), 5);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.end() - 1, 4);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.end() - 1, 4);
//     print_orj_vector(orjVecInsert);

//     std::cout<< "***insert with 3 parameters***\n" <<std::endl;

//     myVecInsert.insert(myVecInsert.begin(), 2, -3);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin(), 2, -3);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.begin() + 1, 2, -2);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin() + 1, 2, -2);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.begin() + 1, 0, 9999);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.begin() + 1, 0, 9999);
//     print_orj_vector(orjVecInsert);

//     myVecInsert.insert(myVecInsert.end() - 1, 2, 7777);
//     print_my_vector(myVecInsert);
//     orjVecInsert.insert(orjVecInsert.end() - 1, 2, 7777);
//     print_orj_vector(orjVecInsert);
// }

// int main()
// {
//     ft::vector<int> vector;
//     ft::vector<int>::iterator it;
//     vector.push_back(1);
//     vector.push_back(2);
//     vector.push_back(3);
//     vector.push_back(4);
//     vector.push_back(5);

//     print_my_vector(vector);
//     it = vector.begin() + 2;
//     it = vector.insert(it, 200);
//     print_my_vector(vector);
//     std::cout << "--------------" << std::endl;
//     std::vector<int> myvector;
//     std::vector<int>::iterator it1;

//     myvector.push_back(1);
//     myvector.push_back(2);
//     myvector.push_back(3);
//     myvector.push_back(4);
//     myvector.push_back(5);

//     it1 = myvector.begin() + 2;
//     it1 = myvector.insert(it1, 200);
//     print_my_vector(myvector);
//     std::cout << "--------------" << std::endl;
//     // test_all();
//     return (0);
// }

int main()
{
    std::cout << "Map test is starting..." << std::endl;
    // mapBegin();
    // mapEnd();
    // mapRBegin();
    // mapREnd();
    // mapEmpty();
    mapSize();
    // mapMaxSize();

    // mapBoxBrackets();
    // mapInsert();
    // mapErase();
    // mapSwap();
    // mapClear();

    // mapKeyComp();
    // mapValueComp();

    // mapFind();
    // mapCount();
    // mapLowerBound();
    // mapUpperBound();
    // mapEqualRange();

    std::cout << "Map test finished" << std::endl;
}
