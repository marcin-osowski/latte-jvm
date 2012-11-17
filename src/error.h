#ifndef ERROR_H
#define ERROR_H

#include <vector>
#include <string>
#include <sstream>

namespace latte_type_check
{

class Error;
class Errors;

class Error
{
public:
    Error(const int _line_no, const std::string &_fn, const char* _msg): line_no(_line_no), fn(_fn), msg(_msg) {}
    Error(const int _line_no, const std::string &_fn, const char* _msg, const char* id): line_no(_line_no), fn(_fn), msg(_msg) {
      msg.append(": `");
      msg.append(id);
      msg.append("'");
    }
    std::string toString() const {
        std::ostringstream ss;
        if(line_no > 0){
          ss << "line " << line_no << ": in " << fn << "(): " << msg << "\n";
        }else{
          ss << fn << ": " << msg << "\n";
        }
        return ss.str();
    }
private:
    int line_no;
    std::string fn;
    std::string msg;
    friend class Errors;
};

class Errors : public std::vector<Error>
{
public:
    std::string toString() const{
        std::ostringstream ss;
        for(auto error : *this){
            ss << error.toString();
        }
        return ss.str();
    }
};
};

#endif
