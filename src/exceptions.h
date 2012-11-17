#ifndef LATTE_EXCEPTIONS_H
#define LATTE_EXCEPTIONS_H

#include <exception>

class LatteException : public std::exception
{
public:
    LatteException () throw() {}
    LatteException (const LatteException&) throw() {}
    LatteException& operator= (const LatteException&) throw() {return *this;}
    virtual ~LatteException() throw() {}
    virtual const char* what() const throw() = 0;
};

#define LATTE_EXCEPTION(NAME)               \
    class NAME : public LatteException      \
    {                                       \
    public:                                 \
        NAME() throw() {}                   \
        NAME(const NAME& ex) throw() {}     \
        ~NAME() throw() {}                  \
        const char* what() const throw(){   \
            return "Latte: " #NAME ;        \
        }                                   \
    }

LATTE_EXCEPTION(InternalErrorException);
LATTE_EXCEPTION(NotImplementedException);
LATTE_EXCEPTION(IdentifierNotFoundException);
LATTE_EXCEPTION(IdentifierRepeatedException);

namespace latte_type_check
{

class TypeCheckException : public LatteException
{
private:
    std::string desc;
public:
    TypeCheckException(int line_number, std::string _desc) throw() {
        throw NotImplementedException();
    }
    ~TypeCheckException() throw(){}
    const char* what() const throw(){
        return desc.c_str();
    }
};
};

#endif //LATTE_EXCEPTIONS_H
