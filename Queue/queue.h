#ifndef Q_H
#define Q_H
#include <iostream>
#include "listsingle.h"

namespace my_std{

template <typename T>
class Queue{

private:
    my_std::List<T> list;

public:
    bool empty() const;
    int size() const;
    T front();
    T back();
    void push(const T& value);
    void pop();

};

}

#include "queue.tpp"

#endif