#include "listsinglecircular.h"

template <typename T>
ListCircular<T>::Node::Node(): data{0},next{nullptr}{}

template <typename T>
ListCircular<T>::Node::Node(T data): data{data},next{nullptr}{}

template <typename T>
ListCircular<T>::ListCircular(): tail{nullptr}{}

template <typename T>
ListCircular<T>::ListCircular(const ListCircular& other): tail{nullptr}{

    if(other.tail==nullptr){
    
        return;
        
    }

    Node* tmp=other.tail->next;

    while(tmp->next!=other.tail->next){

        insertend(tmp->data);

        tmp=tmp->next;

    }

    insertend(tmp->data);

}

template <typename T>
ListCircular<T>::ListCircular(ListCircular&& other): tail{other.tail}{

    other.tail=nullptr;

}

template <typename T>
ListCircular<T>& ListCircular<T>::operator=(const ListCircular& other){

    if(this==&other){

        return *this;

    }

    while(!empty()){

        erasebegin();

    }

    tail=nullptr;

    if(other.tail==nullptr){

        return *this;

    }

    Node* tmp=other.tail->next;

    while(tmp!=other.tail){

        insertend(tmp->data);

        tmp=tmp->next;

    }

    insertend(tmp->data);

    return *this;

}

template <typename T>
ListCircular<T>& ListCircular<T>::operator=(ListCircular&& other){

    if(this==&other){

        return *this;

    }

    while(!empty()){

        erasebegin();

    }

    tail=other.tail;

    other.tail=nullptr;

    return *this;

}

template <typename T>
ListCircular<T>::~ListCircular(){

    if(tail==nullptr) return;

    Node* tmp=tail->next;
    
    while(tmp!=tail){

        tmp=tail->next;

        tail->next=tmp->next;

        delete tmp;

        tmp=tail->next;

    }

    delete tmp;

} 

template <typename T>
void ListCircular<T>::create(){

    int choice=1;

    Node* newnode;

    int number=0;

    while(choice){

        std::cout<<"Please, enter the number!\n";

        std::cin>>number;

        newnode=new Node(number);

        if(tail==nullptr){

            tail=newnode;

            tail->next=newnode;

        }

        else{

            newnode->next=tail->next;

            tail->next=newnode;

            tail=newnode;

        }

        std::cout<<"For continue input 1, 0 otherwise!\n";

        std::cin>>choice;

    }

}

template <typename T>
void ListCircular<T>::display() const{

    if(tail==nullptr){

        std::cout<<"The list is empty!\n";

    }

    else{

        Node* tmp=tail->next;

        while(tmp->next!=tail->next){

            std::cout<<tmp->data<<" ";

            tmp=tmp->next;

        }

        std::cout<<tmp->data<<"\n";

    }

}

template <typename T>
bool ListCircular<T>::empty() const{

    if(tail==nullptr) return true;

    return false;

}

template <typename T>
int ListCircular<T>::size() const{

    if(tail==nullptr) return 0;

    int count=1;

    Node* tmp=tail->next;

    while(tmp->next!=tail->next){

        count++;

        tmp=tmp->next;

    }

    return count;

}

template <typename T>
void ListCircular<T>::insertbegin(T data){

    Node* newnode=new Node(data);

    if(tail==nullptr){

        tail=newnode;

        newnode->next=tail;

    }

    else{

        newnode->next=tail->next;

        tail->next=newnode;

    } 

}

template <typename T>
void ListCircular<T>::insertend(T data){

    Node* newnode=new Node(data);

    if(tail==nullptr){

        tail=newnode;

        newnode->next=tail;

    }

    else{

        newnode->next=tail->next;

        tail->next=newnode;

        tail=newnode;

    }

}

template <typename T>
void ListCircular<T>::insert(T data,int pos){

    if(pos<1 || pos>size()+1){ 
        
        std::cout<<"Invalid position!\n";

        return;

    }
        
    if(pos==1){

        insertbegin(data);

    }

    else if(pos==size()+1){

        insertend(data);

    }

    else{

        int i=1;

        Node* tmp=tail->next;

        while(i<pos-1){

            ++i;

            tmp=tmp->next;

        }

        Node* newnode=new Node(data);

        newnode->next=tmp->next;

        tmp->next=newnode;

    }    

}

template <typename T>
void ListCircular<T>::erasebegin(){

    if(tail==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    if(tail==tail->next){

        delete tail;

        tail=nullptr;

    }

    else{

        Node* tmp=tail->next;

        tail->next=tmp->next;

        delete tmp;
       
    }    

}

template <typename T>
void ListCircular<T>::eraseend(){

    if(tail==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    Node* tmp=tail->next;

    if(tail==tail->next){

        delete tail;

        tail=nullptr;

    }

    else{

        while(tmp->next!=tail){

            tmp=tmp->next;

        }

        tmp->next=tail->next;

        delete tail;

        tail=tmp;

    }    

}

template <typename T>
void ListCircular<T>::erase(int pos){

    if(tail==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    if(pos<1 || pos>size()){

        std::cout<<"Invalid position!\n";

        return;

    }

    if(pos==1){

        erasebegin();

        return;

    }

    if(pos==size()){

        eraseend();

        return;

    }

    Node* tmp=tail->next;

    int i=1;

    while(i<pos-1){

        tmp=tmp->next;

        i++;

    }

    Node* t=tmp->next;

    tmp->next=t->next;

    delete t;

}

template <typename T>
void ListCircular<T>::reverse(){

    if(tail==nullptr) return;

    Node* prev=tail;
    
    Node* current=tail->next;

    Node* next=current->next;

    while(current!=tail){

        current->next=prev;

        prev=current;

        current=next;

        next=current->next;

    }

    current->next=prev;

    tail=next;

}