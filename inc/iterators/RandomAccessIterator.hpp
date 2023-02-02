#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class RandomAccessIterator : public Iterator<T, std::random_access_iterator_tag>
    {
    private:
        typedef RandomAccessIterator<T> randomIterator;
    public:
        RandomAccessIterator() 
        {
            this->_ptr = NULL;
        }
        RandomAccessIterator(const randomIterator &other)
        {
            this->_ptr = other._ptr;
        }
        RandomAccessIterator &operator=(const randomIterator &other)
        {
            if (this == other)
                return (*this);
            *this = other;
            return (*this);
        }
        ~RandomAccessIterator();
        RandomAccessIterator(T* ptr) 
        {
            this->_ptr = ptr;
        }
        RandomAccessIterator &operator--()
        {
            this->_ptr--;
            return (*this);
        }
        RandomAccessIterator operator--(int)
        {
            RandomAccessIterator tmp = *this;
            --(*tmp);
            return (tmp);
        }
        T& operator[](const int n) const
        {
            return (this->_ptr[n]);
        }
        randomIterator operator+(int other)
        {
            return (randomIterator(this->_ptr + other));
        }
        randomIterator operator-(int other)
        {
            return (randomIterator(this->_ptr - other));
        }
    };

}
#endif