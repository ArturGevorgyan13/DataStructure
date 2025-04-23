#include "bst.h"

template <typename T>
Node<T>::Node(T data): data{data},left{nullptr},right{nullptr}{}

template <typename T>
BST<T>::BST(): root{nullptr}{}

template <typename T>
BST<T>::~BST(){

    clear();

}   

template <typename T>
void BST<T>::insert(T data){

    if(root==nullptr){

        root=new Node<T>(data);

        return;

    }

    Node<T>** current=&root;

    while(*current!=nullptr){

        if(data>(*current)->data){

            current=&((*current)->right);

        }

        else if(data<(*current)->data){

            current=&((*current)->left);

        }

        else return;

    }

    *current=new Node<T>(data);

}

template <typename T>
void BST<T>::insertR(T data){

    insertR_h(root,data);

}   

template <typename T>
void BST<T>::insertR_h(Node<T>*& node,T data){

    if(node==nullptr){

        node=new Node<T>(data);

    }

    else if(data>node->data){

        insertR_h(node->right,data);

    }

    else if(data<node->data){

        insertR_h(node->left,data);

    }

}

template <typename T>
bool BST<T>::search(T data){

    Node<T>* current=root;

    while(current!=nullptr){

        if(data==current->data){

            return true;

        }

        else if(data>current->data){

            current=current->right;

        }

        else if(data<current->data){

            current=current->left;

        }

    }

    return false;

}

template <typename T>
bool BST<T>::searchR(T data){

    return searchR_h(root,data);

}

template <typename T>
bool BST<T>::searchR_h(Node<T>* node,T data){

    if(node==nullptr){

        return false;

    }

    if(data<node->data){

       return searchR_h(node->left,data); 

    }

    else if(data>node->data){

        return searchR_h(node->right,data);

    }

    else return true;

}

template <typename T>
void BST<T>::removeR(T data){

    removeR_h(root,data);

}

template <typename T>
void BST<T>::removeR_h(Node<T>*& node,T data){

    if(node==nullptr){

        return;

    }

    if(data>node->data){

        removeR_h(node->right,data);

    }

    else if(data<node->data){

        removeR_h(node->left,data);

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

            Node<T>* successor=findmin_h(node->right);

            node->data=successor->data;

            removeR_h(node->right,successor->data);

        }

    }

}

template <typename T>
Node<T>* BST<T>::findmin_h(Node<T>* node){  

    if(node==nullptr) return nullptr;

    if(node->left==nullptr){

        return node;

    }

    return findmin_h(node->left);

}

template <typename T>
T BST<T>::findmin(){

    return findmin_h(root)->data;

}

template <typename T>
Node<T>* BST<T>::findmax_h(Node<T>* node){

    if(node==nullptr) return nullptr;

    if(node->right==nullptr){

        return node;

    }

    return findmax_h(node->right);

}

template <typename T>
T BST<T>::findmax(){

    return findmax_h(root)->data;

}

template <typename T>
int BST<T>::getheightR(){

    return getheightR_h(root);

}

template <typename T>
int BST<T>::getheightR_h(Node<T>* node){

    if(node==nullptr){

        return -1;

    }

    return std::max(getheightR_h(node->left),getheightR_h(node->right))+1; 

}

template <typename T>
int BST<T>::getheight(){

    int height=-1;

    if(root==nullptr){
        
        return height;
    
    }

    std::queue<Node<T>*> q;

    q.push(root);

    while(!q.empty()){

        int level=q.size();

        ++height;

        for(int i=0;i<level;i++){

            Node<T>* node=q.front();

            q.pop();

            if(node->left){

                q.push(node->left);

            }

            if(node->right){

                q.push(node->right);

            }

        }

    }

    return height;

}

template <typename T>
void BST<T>::preorderR(){

    preorderR_h(root);

}

template <typename T>
void BST<T>::inorderR(){

    inorderR_h(root);

}

template <typename T>
void BST<T>::postorderR(){

    postorderR_h(root);

}

template <typename T>
void BST<T>::preorderR_h(Node<T>* node){

    if(node==nullptr){

        return;

    }

    std::cout<<node->data<<" ";

    preorderR_h(node->left);

    preorderR_h(node->right);

}

template <typename T>
void BST<T>::inorderR_h(Node<T>* node){

    if(node==nullptr){

        return;

    }

    inorderR_h(node->left);

    std::cout<<node->data<<" ";

    inorderR_h(node->right);

}

template <typename T>
void BST<T>::postorderR_h(Node<T>* node){

    if(node==nullptr){

        return;

    }

    postorderR_h(node->left);

    postorderR_h(node->right);

    std::cout<<node->data<<" ";

}

template <typename T>
void BST<T>::preorder(){

    if(root==nullptr) return;

    std::stack<Node<T>*> s;

    s.push(root);

    while(!s.empty()){

        Node<T>* node=s.top();

        s.pop();

        std::cout<<node->data<<" ";

        if(node->right!=nullptr){

            s.push(node->right);

        }

        if(node->left!=nullptr){

            s.push(node->left);

        }

    }

}

template <typename T>
void BST<T>::postorder(){

    if(root==nullptr) return;

    std::stack<Node<T>*> s;

    s.push(root);

    std::stack<int> o;

    while(!s.empty()){

        Node<T>* node=s.top();

        s.pop();

        o.push(node->data);

        if(node->left!=nullptr){

            s.push(node->left);

        }

        if(node->right!=nullptr){

            s.push(node->right);

        }

    }

    while(!o.empty()){

        std::cout<<o.top()<<" ";

        o.pop();

    }

}

template <typename T>
void BST<T>::inorder(){

    if(root==nullptr) return;

    std::stack<Node<T>*> s;

    Node<T>* current=root;

    while(current!=nullptr || !s.empty()){

        while(current!=nullptr){

            s.push(current);

            current=current->left;

        }

        current=s.top();

        s.pop();

        std::cout<<current->data<<" ";

        current=current->right;

    }

}

template <typename T>
void BST<T>::levelorder(){

    if(root==nullptr) return;

    std::queue<Node<T>*> q;

    q.push(root);

    while(!q.empty()){

        Node<T>* node=q.front();

        q.pop();

        std::cout<<node->data<<" ";

        if(node->left!=nullptr){

            q.push(node->left);

        }

        if(node->right!=nullptr){

            q.push(node->right);

        }

    }

}

template <typename T>
void BST<T>::clear(){

    clearR_h(root);

    root=nullptr;

}

template <typename T>
void BST<T>::clearR_h(Node<T>* node){

    if(node==nullptr) return;

    clearR_h(node->left);

    clearR_h(node->right);

    delete node;

}

template class BST<int>;