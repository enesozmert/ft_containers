#ifndef MAP_HPP
#define MAP_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "../exception/map_exception.hpp"
#include "../common/type_traits/type_traits.hpp"

class mapException;
namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class map
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;                            //
            typedef typename Alloc::reference reference;             // Reference to element
            typedef typename Alloc::const_reference const_reference; // Reference to constant element
            typedef typename Alloc::pointer pointer;                 // Pointer to element
            typedef typename Alloc::const_pointer const_pointer;     // Pointer to const element
            typedef ptrdiff_t difference_type;
            typedef std::size_t size_type;
            typedef ft::random_access_iterator<pointer> iterator;
            typedef ft::random_access_iterator<const_pointer> const_iterator;

            typedef ft::reverse_iterator<pointer> reverse_iterator;
            typedef ft::reverse_iterator<const_pointer> const_reverse_iterator;

        private:
            size_type _size;
            size_type _capacity;
            Alloc _allocator;
            value_type *_data;
        public:
        

    };
}

#endif