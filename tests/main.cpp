#include <iostream>
#include <vector>
#include "test.hpp"
#include "../inc/containers/vector.hpp"

using namespace ft;

void print_my_vector(ft::vector<int> v)
{
    ft::vector<int>::iterator it = v.begin();
    std::cout << "print MY vector";
    std::cout << "\n-------------\n";
    std::cout << "capacity: " << v.capacity() << " size: " << v.size() << std::endl;

    std::cout << "datas ---> ";
    while (it != v.end())
        std::cout << *it++ << " ";
    std::cout << "\n-------------\n";
}

int main()
{
    ft::vector<int> vector;
    ft::vector<int>::iterator it;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    print_my_vector(vector);
    it = vector.begin();
    it = vector.insert(it, 200);
    print_my_vector(vector);
    std::cout << "--------------" << std::endl;
    // std::vector<int> myvector;
    // std::vector<int>::iterator it1;

    // myvector.push_back(1);
    // myvector.push_back(2);


    // it1 = myvector.begin();
    // it1 = myvector.insert(it, 200);
    // print_my_vector(vector);
    // test_all();

    return (0);
}
