#ifndef LATTE_TYPE_H
#define LATTE_TYPE_H

#include <string>
#include <boost/operators.hpp>
#include "parser/Absyn.H"
#include "exceptions.h"

/*
 * Class representing any variable type in Latte.
 *
 * Special type ERROR is added to allow Latte type checker
 * continue after first type error.
 * */

namespace latte_type_check
{

enum TYPES {
  INT,
  STR,
  BOOL,
  VOID,
  ERROR
};

class LatteType : boost::equality_comparable<LatteType>
{
public:
  LatteType(latte_parser::Type const* t){
    if(dynamic_cast<latte_parser::TInt const*>(t) != 0){
      type = INT;
    }else if(dynamic_cast<latte_parser::TStr const*>(t) != 0){
      type = STR;
    }else if(dynamic_cast<latte_parser::TBool const*>(t) != 0){
      type = BOOL;
    }else if(dynamic_cast<latte_parser::TVoid const*>(t) != 0){
      type = VOID;
    }else {
      throw InternalErrorException();
    }
  }

  LatteType(LatteType const& rhs) = default;

  LatteType(TYPES _type) : type(_type) {}

public:
  bool operator==(LatteType const& rhs) const{
    return this->type == rhs.type;
  }

  LatteType* clone(){
    return new LatteType(*this);
  }

  std::string toString() const{
    switch(type){
      case INT:
        return std::string("int");
      case STR:
        return std::string("string");
      case BOOL:
        return std::string("boolean");
      case VOID:
        return std::string("void");
      case ERROR:
        return std::string("<error type>");
      default:
        throw InternalErrorException();
    }
  }

private:
  TYPES type;
};

};


#endif
