#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    
    #include <cstddef> 
    template <typename T, typename Category>
    class Iterator
    {
    protected:
    private:
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef Category iterator_category;
        
        pointer _ptr;
        Iterator() : _ptr(NULL)
        {
        }
        Iterator(const Iterator &_iterator)
        {
            this->_ptr = _iterator._ptr;
        }
        Iterator &operator=(const Iterator &_iterator)
        {
            if (this == _iterator)
                return (*this);
            *this = _iterator;
            return (*this);
        }
        ~Iterator() {}
        Iterator(pointer ptr) : _ptr(ptr){};
        reference operator*() const
        {
            return (*_ptr);
        }
        Iterator &operator++()
        {
            _ptr++;
            return (*this);
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*tmp);
            return (tmp);
        }
        bool operator!=(const Iterator &_iterator) const
        {
            return (_ptr != _iterator._ptr);
        }
        bool operator==(const Iterator &_iterator)
        {
            return this->_pointer == _iterator._pointer;
        }

        bool operator!=(const Iterator &_iterator)
        {
            return this->_pointer != _iterator._pointer;
        }

        bool operator<(const Iterator &_iterator)
        {
            return this->_pointer < _iterator._pointer;
        }

        bool operator<=(const Iterator &_iterator)
        {
            return this->_pointer <= _iterator._pointer;
        }

        bool operator>(const Iterator &_iterator)
        {
            return this->_pointer > _iterator._pointer;
        }

        bool operator>=(const Iterator &_iterator)
        {
            return this->_pointer >= _iterator._pointer;
        }
    };
}

#endif