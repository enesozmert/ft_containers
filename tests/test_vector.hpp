#pragma once

#include "test.hpp"

using namespace ft;

template <typename T>
void test_vector_empty(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
{
    T _data = 0;
    test_print(__FUNCTION__, "TEST(ORJINAL)");
    std::cout << std::boolalpha;

    orjinal_vector.push_back(_data);
    test_print(__FUNCTION__, "TEST(ME)");
    std::cout << std::boolalpha;

    my_vector.push_back(_data);
    if (orjinal_vector.empty() == my_vector.empty())
        test_print(__FUNCTION__, "TEST(OK)");
    else
        test_print(__FUNCTION__, "TEST(FAIL)");
    test_print(__FUNCTION__, "TEST(END)");
    test_print("", "****************************************************************");
    return;
}

template <typename T>
void test_vector_size(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
{
    T _data = 0;
    test_print(__FUNCTION__, "TEST(ORJINAL)");
    for (int i = 0; i < 100; i++)
        orjinal_vector.push_back(_data);
    orjinal_vector.pop_back();
    orjinal_vector.push_back(_data);
    test_print(__FUNCTION__, "TEST(ME)");
    for (int i = 0; i < 100; i++)
        my_vector.push_back(_data);
    my_vector.pop_back();
    my_vector.push_back(_data);
    if (orjinal_vector.size() == my_vector.size())
        test_print(__FUNCTION__, "TEST(OK)");
    else
        test_print(__FUNCTION__, "TEST(FAIL)");
    test_print(__FUNCTION__, "TEST(END)");
    test_print("", "****************************************************************");
    return;
}

template <typename T>
void test_vector_max_size(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
{
    T _data = 0;
    test_print(__FUNCTION__, "TEST(ORJINAL)");
    for (int i = 0; i < 100; i++)
        orjinal_vector.push_back(_data);
    orjinal_vector.pop_back();
    test_print(__FUNCTION__, "TEST(ME)");
    for (int i = 0; i < 100; i++)
        my_vector.push_back(_data);
    my_vector.pop_back();
    if (orjinal_vector.max_size() == my_vector.max_size())
        test_print(__FUNCTION__, "TEST(OK)");
    else
        test_print(__FUNCTION__, "TEST(FAIL)");
    test_print(__FUNCTION__, "TEST(END)");
    test_print("", "****************************************************************");
    return;
}

template <typename T>
void test_vector_reserve(std::vector<T> orjinal_vector, ft::vector<T> my_vector)
{
    T _data = 0;
    typename std::vector<T>::size_type sz;
    test_print(__FUNCTION__, "TEST(ORJINAL)");
    {
        sz = orjinal_vector.capacity();
        for (int i = 0; i < 100; ++i)
        {
            orjinal_vector.push_back(_data);
            if (sz != orjinal_vector.capacity())
                sz = orjinal_vector.capacity();
        }

        sz = orjinal_vector.capacity();
        orjinal_vector.reserve(100);
        for (int i = 0; i < 100; ++i)
        {
            orjinal_vector.push_back(i);
            if (sz != orjinal_vector.capacity())
                sz = orjinal_vector.capacity();
        }
    }
    test_print(__FUNCTION__, "TEST(ME)");
    {
        {
            sz = my_vector.capacity();
            for (int i = 0; i < 100; ++i)
            {
                my_vector.push_back(_data);
                if (sz != my_vector.capacity())
                    sz = my_vector.capacity();
            }

            sz = my_vector.capacity();
            my_vector.reserve(100);
            for (int i = 0; i < 100; ++i)
            {
                my_vector.push_back(i);
                if (sz != my_vector.capacity())
                    sz = my_vector.capacity();
            }
        }
    }
    if (orjinal_vector.size() == my_vector.size() && orjinal_vector.capacity() == my_vector.capacity())
        test_print(__FUNCTION__, "TEST(OK)");
    else
        test_print(__FUNCTION__, "TEST(FAIL)");
    test_print(__FUNCTION__, "TEST(END)");
    test_print("", "****************************************************************");
    return;
}