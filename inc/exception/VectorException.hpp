#ifndef VECTOREXCEPTION_HPP
#define VECTOREXCEPTION_HPP

class VectorException : public std::exception
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