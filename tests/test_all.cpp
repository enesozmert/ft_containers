#include "test.hpp"
#include "test_utils.hpp"
#include "test_vector.hpp"
#include "../inc/containers/vector.hpp"

using namespace ft;

void test_all()
{
    ft::vector<int> my_vector;
    std::vector<int> orjinal_vector;

    test_vector_empty<int>(orjinal_vector, my_vector);
    test_vector_size<int>(orjinal_vector, my_vector);
    test_vector_max_size<int>(orjinal_vector, my_vector);
    test_vector_reserve<int>(orjinal_vector, my_vector);
}