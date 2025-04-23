#include "avl.h"

template <typename T>
Node<T>::Node(T data): data{data},left{nullptr},right{nullptr},height{0}{}

template <typename T>
AVL<T>::AVL(): root{nullptr}{}

template <typename T>
AVL<T>::~AVL(){

    clear(root);

}

template <typename T>
int AVL<T>::getheight(Node<T>* node){

    return node==nullptr?-1:node->height;

}

template <typename T>
int AVL<T>::getbalancefactor(Node<T>* node){

    return node?getheight(node->left)-getheight(node->right):0;

}

template <typename T>
Node<T>* AVL<T>::rotateleft(Node<T>* node){

    Node<T>* r=node->right;

    Node<T>* tmp=r->left;

    r->left=node;

    node->right=tmp;

    node->height=std::max(getheight(node->left),getheight(node->right))+1;

    r->height=std::max(getheight(r->left),getheight(r->right))+1;
    
    return node;

}

template <typename T>
Node<T>* AVL<T>::rotateright(Node<T>* node){

    Node<T>* l=node->left;

    Node<T>* tmp=l->right;

    l->right=node;

    node->left=tmp;

    node->height=std::max(getheight(node->left),getheight(node->right))+1;

    l->height=std::max(getheight(l->left),getheight(l->right))+1;
    
    return node;

}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>*& node,T data){

    if(node==nullptr){

        node=new Node<T>(data);

    }

    if(data>node->data){

        node->right=insert(node->right,data);

    }

    else if(data<node->data){

        node->left=insert(node->left,data);

    }

    else return node;

    node->height=std::max(getheight(node->left),getheight(node->right))+1;

    int balance=getbalancefactor(node);

    if(balance>1 && node->left->data>data){
        
        return rotateright(node);

    } 

    if(balance<-1 && node->right->data<data){
        
        return rotateleft(node);

    }

    if(balance>1 && node->left->data<data){

        node->left=rotateleft(node->left);

        return rotateright(node);
        
    }

    if(balance<-1 && node->right->data>data){

        node->right=rotateright(node->right);

        return rotateleft(node);
        
    }

    return node;

}

template <typename T>
Node<T>* AVL<T>::search(Node<T>* node,T data){

    if(node==nullptr){

        return nullptr;

    }

    if(data<node->data){

        return search(node->left,data);

    }

    if(data>node->data){

        return search(node->right,data);

    }

    return node;

}

template <typename T>
Node<T>* AVL<T>::remove(Node<T>*& node,T data){

    if(node==nullptr){

        return nullptr;

    }

    if(data<node->data){

        return remove(node->left,data);

    }

    else if(data>node->data){

        return remove(node->right,data);

    }

    else{

        if(node->left==nullptr){

            Node<T>* tmp=node->right;

            delete node;

            node=tmp;

        }

        else if(node->right==nullptr){

            Node<T>* tmp=node->left;

            delete node;

            node=tmp;

        }

        else{

            Node<T>* successor=findmin(node->right);

            node->data=successor->data;

            return remove(node->right,successor->data);

        }

    }

    //node->height=std::max(getheight(node->left),getheight(node->right))+1;

    int balance=getbalancefactor(node);

    if(balance>1 && node->left->data>data){
        
        return rotateright(node);

    } 

    if(balance<-1 && node->right->data<data){
        
        return rotateleft(node);

    }

    if(balance>1 && node->left->data<data){

        node->left=rotateleft(node->left);

        return rotateright(node);
        
    }

    if(balance<-1 && node->right->data>data){

        node->right=rotateright(node->right);

        return rotateleft(node);
        
    }

    return node;

}

template <typename T>
Node<T>* AVL<T>::findmin(Node<T>* node){

    if(node==nullptr){

        return nullptr;

    }

    if(node->left==nullptr){

        return node;

    }

    return findmin(node->left);

}

template <typename T>
void AVL<T>::clear(Node<T>* node){

    if(node==nullptr){

        return;

    }

    clear(node->left);

    clear(node->right);

    delete node;

}

template <typename T>
void AVL<T>::preorder(Node<T>* node){

    if(node==nullptr) return;

    std::cout<<node->data<<std::endl;

    preorder(node->left);

    preorder(node->right);

}

template <typename T>
void AVL<T>::inorder(Node<T>* node){

    if(node==nullptr) return;

    inorder(node->left);

    std::cout<<node->data<<std::endl;

    inorder(node->right);

}

template <typename T>
void AVL<T>::postorder(Node<T>* node){

    if(node==nullptr) return;

    postorder(node->left);

    postorder(node->right);

    std::cout<<node->data<<std::endl;

}

template class AVL<int>;