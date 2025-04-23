#include "rbt.h"

template <typename T>
Node<T>::Node(): data{0},parent{nullptr},left{nullptr},right{nullptr}{}

template <typename T>
Node<T>::Node(T val): data{val},parent{nullptr},left{nullptr},right{nullptr}{}

template <typename T>
RBT<T>::RBT(){

    nil=new Node<T>;

    nil->color=Color::BLACK;

    root=nil;

}

template <typename T>
void RBT<T>::clear(){

    clear(root);

}

template <typename T>
void RBT<T>::clear(Node<T>*& node){

    if(node!=nil){

        clear(node->left);

        clear(node->right);

        delete node;

    }

}

template <typename T>
RBT<T>::~RBT(){

    clear();

    delete nil;

}

template <typename T>
void RBT<T>::insert(const T& value){

    Node<T>* newnode=new Node{value};

    Node<T>* current=root;

    Node<T>* parentnode=nil;

    while(current!=nil){

        parentnode=current;

        if(newnode->data<current->data){

            current=current->left;

        }

        if(newnode->data>current->data){

            current=current->right;

        }

    }

    newnode->parent=parentnode;

    if(parentnode==nil){

        root=newnode;

    }

    else if(newnode->data<parentnode->data){

        parentnode->left=newnode;

    }

    else{

        parentnode->right=newnode;

    }

    newnode->left=nil;

    newnode->right=nil;

    newnode->color=Color::RED;

    fixInsertion(newnode);

}

template <typename T>
void RBT<T>::fixInsertion(Node<T>*& node){

    while(node->parent->color==Color::RED){

        Node<T>* grandparent=node->parent->parent;

        if(node->parent==grandparent->left){

            Node<T>* uncle=grandparent->right;

            if(uncle->color==Color::RED){

                node->parent->color=Color::BLACK;

                uncle->color=Color::BLACK;

                grandparent->color=Color::RED;

                node=grandparent;

            }

            else{

                if(node==node->parent->right){

                    node=node->parent;

                    rotateLeft(node);

                }

                node->parent->color=Color::BLACK;

                grandparent->color=Color::RED;

                rotateRight(grandparent);

            }

        }

        else if(node->parent==grandparent->right){

            Node<T>* uncle=grandparent->left;

            if(uncle->color==Color::RED){

                node->parent->color=Color::BLACK;

                uncle->parent->color=Color::BLACK;

                grandparent->color=Color::RED;

                node=grandparent;

            }

            else{

                if(node==node->parent->left){

                    node=node->parent;

                    rotateRight(node);

                }

                node->parent->color=Color::BLACK;

                grandparent->color=Color::RED;

                rotateLeft(grandparent);

            }

        }

    }

    root->color=Color::BLACK;

}

template <typename T>
void RBT<T>::rotateLeft(Node<T>*& node){

    Node<T>* rightchild=node->right;

    node->right=rightchild->left;

    if(rightchild->left!=nil){

        rightchild->left->parent=node;

    }

    rightchild->parent=node->parent;

    //need to understand

    if(node->parent==nil){

        root=rightchild;

    }

    else if(node==node->parent->left){

        node->parent->left=rightchild;

    }

    else{

        node->parent->right=rightchild;

    }

    rightchild->left=node;

    node->parent=rightchild;

}

template <typename T>
void RBT<T>::rotateRight(Node<T>*& node){

    Node<T>* leftchild=node->left;

    node->left=leftchild->right;

    if(leftchild->right!=nil){

        leftchild->right->parent=node;

    }

    leftchild->parent=node->parent;

    //need to understand

    if(node->parent==nil){

        root=leftchild;

    }

    else if(node=node->parent->right){

        node->parent->right=leftchild;

    }

    else{

        node->parent->left=leftchild;

    }

    leftchild->right=node;

    node->parent=leftchild;

}

template <typename T>
void RBT<T>::remove(const T& value){

    removeHelper(root,value);

    

}

template class RBT<int>;