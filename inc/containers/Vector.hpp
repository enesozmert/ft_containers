#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "../iterators/random_access_iterator.hpp"
#include "../exception/vector_exception.hpp"
#include "../common/type_traits/type_traits.hpp"
#include "../common/distance/distance.hpp"

class vectorException;
namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
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
        size_type _size;
        size_type _capacity;
        size_type _max_size;
        Alloc _allocator;
        value_type *_data;
    public:
        vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _max_size(0), _allocator(alloc), _data(NULL) {}

        vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc), _data(this->_allocator.allocate(this->_capacity))
        {
            for (size_type i = 0; i < this->_size; i++)
                this->_allocator.construct(&this->_data[i], val);
        }

        vector(const vector &vector)
        {
            this->_size = vector._size;
            this->_capacity = vector._capacity;
            this->_max_size = vector._max_size;
            this->_allocator = vector._allocator;
            this->_data = vector._data;
        }
        vector &operator=(const vector &vector)
        {
            if (this == &vector)
                return (*this);
            *this = vector;
            return (*this);
        }
        ~vector(){};
        iterator begin(){return iterator(this->_data);}
        iterator end(){return iterator(this->_data + this->_size);}
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
        void swap(vector &x)
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
        size_type size() const
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
            this->_reAlloc(n);
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
        
        reference at (size_type n)
        {
            if (!positionCheck(n))
                throw vector_exception::OutOfRange();
            return (this->_data[n]);
        }

        const_reference at (size_type n) const
        {
            if (!positionCheck(n))
                throw vector_exception::OutOfRange();
            return (this->_data[n]);
        }

        reference back()
        {
            return (_data[_size - 1]);
        }

        const_reference back() const
        {
            return (_data[_size - 1]);
        }
        //iter
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            size_type i = 0;
            size_type n = 0;

            n = last - first;
            for (; i < n; i++)
                this->_allocator.destroy(i + this->_data);
            _reAlloc(n);
            while (first != last)
            {
                this->_allocator.construct(&this->_data[i], *(first++));
                i++;
            }
            this->_size = n;
        }
        void assign (size_type n, const value_type& val)
        {
            size_type i = 0;

            for (; i < _size; i++)
                this->_allocator.destroy(i + _data);
            _reAlloc(n);
            i = 0;
            for (; i < n; i++)
                this->_allocator.construct(_data + i, static_cast<T>(val));
            _size = n;
        }

        iterator erase (iterator position)
        {
            this->_allocator.destroy(&(*position));
            for (size_type i = 0; i < _size - 1; i++)
                this->_allocator.construct(&_data[i], _data[i]);
            _size--;
            return (position);
        }
        // iterator erase (iterator first, iterator last)
        // {
            
        // }

        bool positionCheck(size_type n)
        {
            if (n < 0 || n >= this->_size)
                return (false);
            return (true);
        }

    };
}

#endif