#ifndef AVL_H
#define AVL_H
#include <iostream>

template <typename T>
class Node{

public:
    T data;
    Node<T>* left;
    Node<T>* right;
    int height;

public:
    Node(T data);

};

template <typename T>
class AVL{

public:
    Node<T>* root;

public:
    AVL();
    ~AVL();

public:
    int getheight(Node<T>* node);
    int getbalancefactor(Node<T>* node);
    Node<T>* insert(Node<T>*& node,T data);
    Node<T>* search(Node<T>* node,T data);
    Node<T>* remove(Node<T>*& node,T data);
    Node<T>* rotateleft(Node<T>* node);
    Node<T>* rotateright(Node<T>* rode);
    void clear(Node<T>* node); 
    Node<T>* findmin(Node<T>* node);
    void preorder(Node<T>* node);
    void inorder(Node<T>* node); 
    void postorder(Node<T>* node); 

};

#endif