#ifndef VECTOR_EXCEPTION_HPP
#define VECTOR_EXCEPTION_HPP

#include <exception>

class vector_exception : public std::exception
{
    public:
        class OutOfRange : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Exception : Out Of Range");
                }
        };
};
#endif