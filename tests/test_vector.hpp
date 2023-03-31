// #pragma once

// #include "test.hpp"
// #include <iostream>

// using namespace ft;

// template <typename T>
// void test_vector_empty(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     // std::cout << typeid(_data).name() << std::endl;
//     // if (strcmp(typeid(_data).name(), "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") == 0)
//     //     _data = "enes";
//     // else if (strcmp(typeid(_data).name(), "i"))
//     //     _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     // std::cout << std::boolalpha;

//     orjinal_vector.push_back(_data);
//     test_print(__FUNCTION__, "TEST(ME)");
//     // std::cout << std::boolalpha;

//     my_vector.push_back(_data);
//     if (orjinal_vector.empty() == my_vector.empty())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_size(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.pop_back();
//     orjinal_vector.push_back(_data);
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.pop_back();
//     my_vector.push_back(_data);
//     if (orjinal_vector.size() == my_vector.size())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_max_size(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.pop_back();
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.pop_back();
//     if (orjinal_vector.max_size() == my_vector.max_size())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_reserve(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     typename std::vector<T>::size_type sz;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     {
//         sz = orjinal_vector.capacity();
//         for (int i = 0; i < 100; ++i)
//         {
//             orjinal_vector.push_back(_data);
//             if (sz != orjinal_vector.capacity())
//                 sz = orjinal_vector.capacity();
//         }

//         sz = orjinal_vector.capacity();
//         orjinal_vector.reserve(100);
//         for (int i = 0; i < 100; ++i)
//         {
//             orjinal_vector.push_back(i);
//             if (sz != orjinal_vector.capacity())
//                 sz = orjinal_vector.capacity();
//         }
//     }
//     test_print(__FUNCTION__, "TEST(ME)");
//     {
//         {
//             sz = my_vector.capacity();
//             for (int i = 0; i < 100; ++i)
//             {
//                 my_vector.push_back(_data);
//                 if (sz != my_vector.capacity())
//                     sz = my_vector.capacity();
//             }

//             sz = my_vector.capacity();
//             my_vector.reserve(100);
//             for (int i = 0; i < 100; ++i)
//             {
//                 my_vector.push_back(i);
//                 if (sz != my_vector.capacity())
//                     sz = my_vector.capacity();
//             }
//         }
//     }
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_capacity(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     int sz = 100;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");

//     std::size_t orjinal_cap = orjinal_vector.capacity();
//     while (sz-- > 0)
//     {
//         orjinal_vector.push_back(_data);
//         if (orjinal_cap != orjinal_vector.capacity())
//             orjinal_cap = orjinal_vector.capacity();
//     }
//     test_print(__FUNCTION__, "TEST(ME)");
//     sz = 100;
//     std::size_t my_cap = my_vector.capacity();
//     while (sz-- > 0)
//     {
//         my_vector.push_back(_data);
//         if (my_cap != my_vector.capacity())
//             my_cap = my_vector.capacity();
//     }
//     if (orjinal_vector.size() == my_vector.size() 
//         && orjinal_cap == my_cap 
//             && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_clear(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.pop_back();
//     orjinal_vector.push_back(_data);
//     orjinal_vector.clear();
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.pop_back();
//     my_vector.push_back(_data);
//     my_vector.clear();
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_insert(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     test_print(__FUNCTION__, "TEST(ME)");
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_erase(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.pop_back();
//     orjinal_vector.push_back(_data);
//     orjinal_vector.erase (orjinal_vector.begin()+5);
//     orjinal_vector.erase (orjinal_vector.begin(),orjinal_vector.begin()+3);
//     test_print(__FUNCTION__, "TEST(ME)");
//         for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.pop_back();
//     my_vector.push_back(_data);
//     my_vector.erase (my_vector.begin()+5);
//     my_vector.erase (my_vector.begin(),my_vector.begin()+3);
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_push_back(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = 0;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.push_back(_data);
//     test_print(__FUNCTION__, "TEST(ME)");
//         for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.push_back(_data);
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_pop_back(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = INT_MAX;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     // orjinal_vector.push_back(_data);
//     orjinal_vector.pop_back();
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     // my_vector.push_back(_data);
//     my_vector.pop_back();
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_resize(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = INT_MAX;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.resize(5);
//     orjinal_vector.resize(8,100);
//     orjinal_vector.resize(12);
//     orjinal_vector.pop_back();
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.resize(5);
//     my_vector.resize(8,100);
//     my_vector.resize(12);
//     my_vector.pop_back();
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }

// template <typename T>
// void test_vector_swap(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
// {
//     T _data = INT_MAX;
//     test_print(__FUNCTION__, "TEST(ORJINAL)");
//     for (int i = 0; i < 100; i++)
//         orjinal_vector.push_back(_data);
//     orjinal_vector.resize(5);
//     orjinal_vector.resize(8,100);
//     orjinal_vector.resize(12);
//     orjinal_vector.pop_back();
//     test_print(__FUNCTION__, "TEST(ME)");
//     for (int i = 0; i < 100; i++)
//         my_vector.push_back(_data);
//     my_vector.resize(5);
//     my_vector.resize(8,100);
//     my_vector.resize(12);
//     my_vector.pop_back();
//     if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
//         test_print(__FUNCTION__, "TEST(OK)");
//     else
//         test_print(__FUNCTION__, "TEST(FAIL)");
//     test_print(__FUNCTION__, "TEST(END)");
//     test_print("", "****************************************************************");
//     return;
// }
