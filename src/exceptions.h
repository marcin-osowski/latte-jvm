#ifndef LATTE_EXCEPTIONS_H
#define LATTE_EXCEPTIONS_H

#include <exception>

/*
 * Custom exception classes used in Latte compiler.
 * */

class LatteException : public std::exception
{
public:
    LatteException () throw() {}
    LatteException (const LatteException&) throw(): std::exception() {}
    LatteException& operator= (const LatteException&) throw() {return *this;}
    virtual ~LatteException() throw() {}
    virtual const char* what() const throw() = 0;
};

#define LATTE_EXCEPTION(NAME)               \
    class NAME : public LatteException      \
    {                                       \
    public:                                 \
        NAME() throw() {}                   \
        NAME(const NAME& ex __attribute__((__unused__))) throw() : LatteException() {} \
        ~NAME() throw() {}                  \
        const char* what() const throw(){   \
            return "Latte: " #NAME ;        \
        }                                   \
    }

LATTE_EXCEPTION(InternalErrorException);
LATTE_EXCEPTION(NotImplementedException);
LATTE_EXCEPTION(IdentifierNotFoundException);
LATTE_EXCEPTION(IdentifierRepeatedException);


#endif //LATTE_EXCEPTIONS_H
