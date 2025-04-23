#ifndef L_H
#define L_H
#include <iostream>

namespace my_std{

template <typename T>
class Node{

private:
    T data;
    Node<T>* next;

public:
    Node();
    Node(T data);

public:    
    T getdata();
    Node<T>* getnext() const;
    void setnext(Node<T>* node );
    void setdata(T dat);

};

template <typename T>
class List{

private:
    Node<T>* head;

public:
    List();
    ~List();
    List(const List& other);
    List(List&& other);
    List& operator=(const List& other);
    List& operator=(List&& other);

public:
    T front();
    T back();
    bool empty() const;
    int size() const;
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void insert(Node<T>* node,const T& value);
    void erase(Node<T>* node);
    void clear();
    Node<T>* find(const T& value);
    void reverse();
    void merge(List& other);

};

}

#include "listsingle.tpp"

#endif