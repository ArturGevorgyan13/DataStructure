#ifndef S_H
#define S_H
#include <iostream>
#include "vector.h"

namespace my_std{

template <typename T,int size=100>
class Stack{

private:
    Vector<T> vec;

public:
    Stack();
    ~Stack();

public:
    void push(const T& element);
    T pop();
    T top() const;
    bool isempty() const;
    int ssize() const;
    void clear();

};

}

#include "stack.tpp"

#endif