#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <exception>

class stack_exception : public std::exception
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