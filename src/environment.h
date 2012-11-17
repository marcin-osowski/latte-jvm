#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <forward_list>
#include <unordered_map>
#include <string>
#include <boost/utility.hpp>
#include <boost/range/adaptors.hpp>
#include <iostream>
#include <memory>
#include "parser/Absyn.H"
#include "exceptions.h"

template<typename T>
class Pusher;

template<typename T>
class Environment;

template<typename T>
class Pusher
{
public:
    Pusher(Pusher<T> const& rhs): env(rhs.env), counter(rhs.counter){
    }
    Pusher(Environment<T>& _env): env(_env), counter(new int){
        env.push();
    }
    Pusher<T>& operator=(Pusher<T> const& rhs) = delete;
    ~Pusher() {
        if(counter.use_count() == 1)
          env.pop();
    }

private:
    Environment<T> &env;
    std::shared_ptr<int> counter;
};

template<typename T>
class Environment
{
private:
    typedef std::unordered_map<std::string, T> mapT;
    friend class Pusher<T>;

public:
    Environment(){
        push();
    }
    ~Environment(){}
    void insert(const std::string& id, const T& t){
        if(stack.front().find(id) != stack.front().end())
            throw IdentifierRepeatedException();
        stack.front()[id] = t;

    }

    Environment<T>& operator=(Environment<T> const& rhs) = delete;

    T& operator[](const std::string& id){
        for(auto i = stack.begin(); i != stack.end(); ++i){
            auto elem = i->find(id);
            if(elem != i->end())
                return elem->second;
        }
        throw IdentifierNotFoundException();
    }

    std::string toString() const{
      mapT outputMap;
      for(auto m : boost::adaptors::reverse(stack)){
        for(auto kv : m){
          outputMap[kv.first] = kv.second;
        }
      }
      std::string outputStr;
      for(auto kv : outputMap){
        outputStr.append(kv.first);
        outputStr.append(" :: ");
        outputStr.append(kv.second->toString());
        outputStr.append("\n");
      }
      return outputStr;
    }

    Pusher<T> pusher(){
      return Pusher<T>(*this);
    }

private:
    void push(){
        stack.push_front(mapT());
    }
    void pop(){
        stack.pop_front();
    }
    std::list<mapT> stack;
    
};

#endif //ENVIRONMENT_H
