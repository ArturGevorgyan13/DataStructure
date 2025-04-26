#ifndef LC_H
#define LC_H
#include <iostream>

template <typename T>
class ListCircular{

private:
    class Node{

    public:
        T data;
        Node* next;

    public:
        Node();
        Node(T data);

    };

private:    
    Node* tail;

public:
    ListCircular();
    ~ListCircular();
    ListCircular(const ListCircular& other);
    ListCircular(ListCircular&& other);
    ListCircular& operator=(const ListCircular& other);
    ListCircular& operator=(ListCircular&& other);

public:
    bool empty() const;
    int size() const;
    void create();
    void insertbegin(T data);
    void insertend(T data);
    void insert(T data,int pos);
    void erasebegin();
    void eraseend();
    void erase(int pos);
    void display() const;
    void reverse();

};

#include "listsinglecircular.tpp"

#endif