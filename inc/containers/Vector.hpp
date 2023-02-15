#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "../iterators/ReverseIterator.hpp"
#include "../iterators/BidirectionalIterator.hpp"
#include "../exception/VectorException.hpp"

class VectorException;
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
        typedef ft::ReverseIterator<T> reverseIterator;
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
                this->_allocator.construct(&this->_data[i], val);
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
        ~Vector(){};
        void _reAlloc(size_type newCapacity)
        {
            value_type *newBlock;

            if (newCapacity < this->_capacity)
                return;
            newBlock = this->_allocator.allocate(newCapacity);
            for (size_type i = 0; i < this->_size; i++)
                this->_allocator.construct(&newBlock[i], this->_data[i]);
            this->_allocator.deallocate(this->_data, this->_capacity);
            this->_data = newBlock;
            this->_capacity = newCapacity;
        }
        void _smart_reAlloc(size_type newCapacity)
        {
            if (newCapacity <= this->_capacity)
                return;
            if (this->_size == 0)
                this->_reAlloc(1);
            else if (newCapacity > (this->_size * 2))
                this->_reAlloc(newCapacity);
            else
                this->_reAlloc(this->_size * 2);
        }
        reference operator[](int index)
        {
            return _data[index];
        }
        allocator_type get_allocator() const
        {
            return (this->_allocator);
        }
        void push_back(value_type value)
        {
            this->_smart_reAlloc(this->_size + 1);
            this->_allocator.construct(&this->_data[this->_size], value);
            this->_size++;
        }
        void clear()
        {
            this->_allocator.destroy(this->_data);
            this->_size = 0;
        }
        void pop_back()
        {
            this->_smart_reAlloc(this->_size - 1);
            for (size_type i = 0; i < this->_size - 1; i++)
                this->_allocator.construct(&this->_data[i], this->_data[i]);
            this->_size--;
        }
        void swap(Vector &x)
        {
            size_t tmp_size = x._size;
            size_t tmp_capacity = x._capacity;
            Alloc tmp_allocator = x._allocator;
            value_type *tmp_data = x._data;

            x._size = this->_size;
            x._capacity = this->_capacity;
            x._allocator = this->_allocator;
            x._data = this->_data;

            this->_size = tmp_size;
            this->_capacity = tmp_capacity;
            this->_allocator = tmp_allocator;
            this->_data = tmp_data;
        }
        size_type capacity() const
        {
            return (this->_capacity);
        }
        size_t size() const
        {
            return this->_size;
        }
        size_type max_size() const
        {
            return (this->_allocator.max_size());
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n == this->_size)
                return;
            size_type i = 0;
            this->_smart_reAlloc(n);
            size_type first = std::min(this->_size, n);
            for (; i < first; i++)
                this->_allocator.construct(&this->_data[i], this->_data[i]);
            for (; i < n; i++)
                this->_allocator.construct(&this->_data[i], static_cast<T>(val));
            this->_size = n;
        }
        void reserve(size_type n)
        {
            if (n > this->_capacity)
                this->_reAlloc(n);
        }
        bool empty() const
        {
            return (this->_size == 0 ? true : false);
        }
        reference front()
        {
            return (this->_data[0]);
        }
        const_reference front() const
        {
            return (this->_data[0]);
        }

        //iter
        template <class iterator>  void assign (iterator first, iterator last)
        {
            (void)last;
            (void)first;
            this->_smart_reAlloc();
        }
        void assign (size_type n, const value_type& val)
        {
            this->_smart_reAlloc(n);
            for (size_type i = 0; i < n; i++)
                this->_allocator.construct(&this->_data[i], static_cast<T>(val));
        }

        bool positionCheck(int n)
        {
            if (n < 0 || n >= this->_size)
                return (false);
            return (true);
        }

        reference at (size_type n)
        {
            if (!positionCheck(n))
                VectorException::OutOfRange();
            return (this->_data[n]);
        }

        const_reference at (size_type n) const
        {
            if (!positionCheck(n))
                VectorException::OutOfRange();
            return (this->_data[n]);
        }
    };
}

#endif