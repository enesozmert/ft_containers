#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
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
        explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _allocator(alloc), _data(NULL) {}
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc), _data(0)
        {
            // for (size_type i = 0; i < this->_size; i++)
            //     this->_allocator.construct(&this->_data[i], val);
            assign(n, val);
        }
        template <class InputIterator>
        explicit vector(InputIterator first, InputIterator sec, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true) : _size(0), _capacity(0), _data(NULL), _allocator(alloc)
        {
            assign(first, sec);
        };

    public:
        vector(const vector &vector)
        {
            this->_size = vector._size;
            this->_capacity = vector._capacity;
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

    public:
        iterator begin() { return (iterator(this->_data)); };
        const_iterator begin() const { return (const_iterator(this->_data)); };
        iterator end() { return (iterator(begin() + size())); };
        const_iterator end() const { return (const_iterator(begin() + size())); };

        reverse_iterator rbegin() { return (reverse_iterator((end()).base())); };
        const_reverse_iterator rbegin() const { return (const_reverse_iterator((end()).base())); };
        reverse_iterator rend() { return (reverse_iterator((begin()).base())); };
        const_reverse_iterator rend() const { return (const_reverse_iterator((begin()).base())); };
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
        void pop_back(void)
        {
            if (this->_size == 0)
                return;
            this->_allocator.destroy(this->_data + this->_size - 1);
            this->_size--;
            this->_capacity--;
        }
        void swap(vector &vector)
        {
            std::swap(vector._size, this->_size);
            std::swap(vector._capacity, this->_capacity);
            std::swap(vector._data, this->_data);
            std::swap(vector._allocator, this->_allocator);
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

        reference back()
        {
            return (_data[_size - 1]);
        }

        const_reference back() const
        {
            return (_data[_size - 1]);
        }

        reference at(size_type n)
        {
            if (!positionCheck(n))
                throw vector_exception::OutOfRange();
            return (this->_data[n]);
        }

        const_reference at(size_type n) const
        {
            if (!positionCheck(n))
                throw vector_exception::OutOfRange();
            return (this->_data[n]);
        }
        // iter
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true)
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
        void assign(size_type n, const value_type &val)
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

        iterator erase(iterator position)
        {
            iterator tmp(position);
            ++tmp;
            return (this->erase(position, tmp));
        }
        iterator erase(iterator first, iterator last)
        {
            difference_type n = last - first;
            iterator new_end = std::copy(last, this->end(), first);
            for (iterator it = new_end; it != this->end(); ++it)
                this->_allocator.destroy(&(*it));
            this->_size -= n;
            return new_end;
        }
        iterator insert(iterator position, const value_type &val)
        {
            size_type index = position - begin();
            if (this->_size >= this->_capacity)
            {
                _smart_reAlloc(this->_size + 1);

                position = begin() + index;
            }
            iterator last = end() - 1;
            while (last >= position)
            {
                *(last + 1) = *last;
                --last;
            }
            this->_allocator.construct(&(*(position)), val);
            ++this->_size;
            return (begin() + index);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type index = position - begin();
            if (this->_size + n > this->_capacity)
            {
                _smart_reAlloc(this->_size + n);
                position = begin() + index;
            }
            iterator last = end() - 1;
            while (last >= position)
            {
                *(last + n) = *last;
                --last;
            }
            for (iterator it = position; it != position + n; ++it)
                this->_allocator.construct(&(*it), val);
            this->_size += n;
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
        {
            difference_type const idx = position - this->begin();
            difference_type const old_end_idx = this->end() - this->begin();
            iterator old_end, end;
            size_type dist = last - first;
            this->resize(this->_size + dist);

            end = this->end();
            position = this->begin() + idx;
            old_end = this->begin() + old_end_idx;
            while (old_end != position)
                *--end = *--old_end;
            while (first != last)
                *position++ = *first++;
        }

        bool positionCheck(size_type n)
        {
            if (n < 0 || n >= this->_size)
                return (false);
            return (true);
        }
    };
}
#endif
