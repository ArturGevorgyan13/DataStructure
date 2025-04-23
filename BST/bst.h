#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class Node{

public:
    T data;
    Node<T>* left;
    Node<T>* right;

public:
    Node(T data); 

};

template <typename T>
class BST{

private:
    Node<T>* root; 

public:
    BST();
    ~BST();

public:
    void insert(T data);
    void insertR(T data);
    bool search(T data);
    bool searchR(T data);
    void removeR(T data);

public:
    void inorderR();
    void preorderR();
    void postorderR();
    void inorder();
    void preorder();
    void postorder();
    void levelorder();

public:
    T findmin();
    T findmax();
    int getheightR();
    int getheight();
    void clear();

private:    
    void insertR_h(Node<T>*& node,T data);
    bool searchR_h(Node<T>* node,T data);
    void removeR_h(Node<T>*& node,T data);
    Node<T>* findmin_h(Node<T>* node);
    Node<T>* findmax_h(Node<T>* node);
    int getheightR_h(Node<T>* node);
    void preorderR_h(Node<T>* node);
    void inorderR_h(Node<T>* node);
    void postorderR_h(Node<T>* node);
    void clearR_h(Node<T>* node);

};

#endif