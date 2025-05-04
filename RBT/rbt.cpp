#include "rbt.h"

template <typename T>
Node<T>::Node(): data{},parent{nullptr},left{nullptr},right{nullptr},color{Color::BLACK}{}

template <typename T>
Node<T>::Node(T val): data{val},parent{nullptr},left{nullptr},right{nullptr},color{Color::RED}{}

template <typename T>
RBT<T>::RBT(){

    nil=new Node<T>;

    nil->color=Color::BLACK;

    root=nil;

}

template <typename T>
void RBT<T>::clear(){

    clear(root);

    delete nil;

}

template <typename T>
void RBT<T>::clear(Node<T>* node){

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

    fixInsertion(newnode);

}

template <typename T>
void RBT<T>::fixInsertion(Node<T>* node){

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

                uncle->color=Color::BLACK;

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
void RBT<T>::rotateLeft(Node<T>* node){

    Node<T>* rightchild=node->right;

    node->right=rightchild->left;

    if(rightchild->left!=nil){

        rightchild->left->parent=node;

    }

    rightchild->parent=node->parent;

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
void RBT<T>::rotateRight(Node<T>* node){

    Node<T>* leftchild=node->left;

    node->left=leftchild->right;

    if(leftchild->right!=nil){

        leftchild->right->parent=node;

    }

    leftchild->parent=node->parent;

    if(node->parent==nil){

        root=leftchild;

    }

    else if(node==node->parent->right){

        node->parent->right=leftchild;

    }

    else{

        node->parent->left=leftchild;

    }

    leftchild->right=node;

    node->parent=leftchild;

}

template <typename T>
T RBT<T>::getMin() const{

    return findMin(root)->data;

}

template <typename T>
T RBT<T>::getMax() const{

    return findMax(root)->data;

}

template <typename T>
Node<T>* RBT<T>::findMin(Node<T>* node) const{

    while(node->left!=nil){

        node=node->left;

    }

    return node;

}

template <typename T>
Node<T>* RBT<T>::findMax(Node<T>* node) const{

    while(node->right!=nil){

        node=node->right;

    }

    return node;

}

template <typename T>
bool RBT<T>::search(const T& value) const{

    Node<T>* current=root;

    while(current!=nil){

        if(current->data>value){

            current=current->right;

        }

        else if(current->data<value){

            current=current->left;

        }

        else return true;

    }

    return false;

}

template <typename T>
bool RBT<T>::isEmpty() const{

    return root==nil;

}

template <typename T>
void RBT<T>::inorderTraversal(){

    inorderTraversal(root);

    std::cout<<"\n";

}

template <typename T>
void RBT<T>::levelorderTraversal(){

    levelorderTraversal(root);

    std::cout<<"\n";

}

template <typename T>
void RBT<T>::inorderTraversal(Node<T>* node){

    if(node!=nil){

        inorderTraversal(node->left);

        std::cout<<node->data<<std::endl;

        inorderTraversal(node->right);

    }

}

template <typename T>
void RBT<T>::levelorderTraversal(Node<T>* node){

    if(node==nil) return;

    std::queue<Node<T>*> q;

    q.push(node);

    while(!q.empty()){

        Node<T>* tmp=q.front();

        q.pop();

        std::cout<<tmp->data;

        if(tmp->left){

            q.push(tmp->left);

        }

        if(tmp->right){

            q.push(tmp->right);

        }

    }

}

template <typename T>
void RBT<T>::transplant(Node<T>* u,Node<T>* v){

    if(u->parent==nil){

        root=v;

    }

    else if(u==u->parent->left){

        u->parent->left=v;

    }

    else u->parent->right=v;

    v->parent=u->parent;

}

template <typename T>
void RBT<T>::remove(const T& value){

    Node<T>* current=root;

    while(current!=nil){

        if(current->data==value) break;

        else if(current->data>value) current=current->left;

        else if(current->data<value) current=current->right;

    }

    if(current==nil) return;

    Node<T>* tmp1=current;

    Color col=tmp1->color;

    Node<T>* tmp2;

    if(tmp1->left==nil){

        tmp2=tmp1->right;

        transplant(current,current->right);

    }

    else if(tmp1->right==nil){

        tmp2=tmp1->left;

        transplant(current,current->left);

    }

    else{

        tmp1=findMin(current->right);

        col=tmp1->color;

        tmp2=tmp1->right;

        if(tmp1->parent==current){

            tmp2->parent=tmp1;

        }

        else{

            transplant(tmp1,tmp1->right);

            tmp1->right=current->right;

            tmp1->right->parent=tmp1;

        }

        transplant(current,tmp1);

        tmp1->left=current->left;

        tmp1->left->parent=tmp1;

        tmp1->color=current->color;

    }

    delete current;

    if(col==Color::BLACK){

        fixDeletion(tmp2);

    }

}

template <typename T>
void RBT<T>::fixDeletion(Node<T>* x){

    while(x!=root && x->color==Color::BLACK){

        if(x==x->parent->left){

            Node<T>* w=x->parent->right;

            if(w->color==Color::RED){

                w->color=Color::BLACK;

                x->parent->color=Color::RED;

                rotateLeft(x->parent);

                w=x->parent->right;

            }

            if(w->left->color==Color::BLACK && w->right->color==Color::BLACK){

                w->color=Color::RED;

                x=x->parent;

            }
            
            else{

                if(w->right->color==Color::BLACK){

                    w->left->color=Color::BLACK;

                    w->color=Color::RED;

                    rotateRight(w);

                    w=x->parent->right;

                }

                w->color=x->parent->color;

                x->parent->color=Color::BLACK;

                w->right->color=Color::BLACK;

                rotateLeft(x->parent);

                x=root;

            }

        }
        
        else{

            Node<T>* w=x->parent->left;

            if(w->color==Color::RED){

                w->color=Color::BLACK;

                x->parent->color=Color::RED;

                rotateRight(x->parent);

                w=x->parent->left;

            }

            if(w->right->color==Color::BLACK && w->left->color==Color::BLACK){

                w->color=Color::RED;

                x=x->parent;

            }
            
            else{

                if(w->left->color==Color::BLACK){

                    w->right->color=Color::BLACK;

                    w->color=Color::RED;

                    rotateLeft(w);

                    w=x->parent->left;

                }

                w->color=x->parent->color;

                x->parent->color=Color::BLACK;

                w->left->color=Color::BLACK;

                rotateRight(x->parent);

                x=root;

            }

        }

    }

    x->color=Color::BLACK;

}


template class RBT<int>;