#ifndef L_H
#define L_H
#include <iostream>

namespace my_std{

template <typename T>
class Node{

private:
    T data;
    Node<T>* next;
    Node<T>* prev;

public:
    Node();
    Node(T data);

public:
    T getdata();
    Node<T>* getnext();
    Node<T>* getprev();
    void setdata(T newdata);
    void setnext(Node<T>* newnext);
    void setprev(Node<T>* newprev);

};

template <typename T>
class List{

private:
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    ~List();
    List(const List<T>& other);
    List(List<T>&& other);
    List<T>& operator=(const List<T>& other);
    List<T>& operator=(List<T>&& other);

public:
    void clear();
    bool isempty() const;
    int size() const;
    Node<T>* search(const T& value);
    void displayforward();
    void displaybackward();
    void inserttail(const T& value);
    void inserthead(const T& value);
    void insertposition(int pos,const T& value);
    void deletetail();
    void deletehead();
    void deleteposition(int pos);

};

}

#endif