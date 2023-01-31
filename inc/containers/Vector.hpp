#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "../iterators/RandomAccessIterator.hpp"
namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class Vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;                            //
        typedef typename Alloc::reference reference;             // Reference to element
        typedef typename Alloc::const_reference const_reference; // Reference to constant element
        typedef typename Alloc::pointer pointer;                 // Pointer to element
        typedef typename Alloc::const_pointer const_pointer;     // Pointer to const element
        typedef ft::RandomAccessIterator<T> iterator;
        typedef ptrdiff_t difference_type;
        typedef std::size_t size_type;

    private:
        size_t _size;
        size_t _capacity;
        size_t _max_size;
        Alloc _allocator;
        value_type *_data;

    public:
        Vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _max_size(0), _allocator(alloc), _data(NULL) {}

        Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc), _data(this->_allocator.allocate(this->_capacity))
        {
            for (size_type i = 0; i < this->_size; i++)
                this->_allocator.construct(&this->_array[i], val);
        }

        Vector(const Vector &vector)
        {
            this->_size = vector._size;
            this->_capacity = vector._capacity;
            this->_max_size = vector._max_size;
            this->_allocator = vector._allocator;
            this->_data = vector._data;
        }
        Vector &operator=(const Vector &vector)
        {
            if (this == &vector)
                return (*this);
            *this = vector;
            return (*this);
        }
        ~Vector();

        
    };
}

#endif