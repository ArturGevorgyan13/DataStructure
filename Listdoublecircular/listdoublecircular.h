#ifndef LC_H
#define LC_H
#include <iostream>

template <typename T>
class DLC{

private:
    class Node{

    public:
        T data;
        Node* next;
        Node* prev;

    public:
        Node();
        Node(T data);

    };

private:
    Node* head;
    Node* tail;

public:
    DLC();
    ~DLC();
    DLC(const DLC& other);
    DLC(DLC&& other);
    DLC& operator=(const DLC& other);
    DLC& operator=(DLC&& other);

public:
    bool empty() const;
    int size() const;
    void insert(T data,int pos);
    void insertbegin(T data);
    void insertend(T data);
    void erase(int pos);
    void erasebegin();
    void eraseend();
    void display() const;
    void reverse();

};

template <typename T>
DLC<T>::Node::Node(): data{},next{nullptr},prev{nullptr}{}

template <typename T>
DLC<T>::Node::Node(T data): data{data},next{nullptr},prev{nullptr}{}

template <typename T>
DLC<T>::DLC(): head{nullptr},tail{nullptr}{}

template <typename T>
DLC<T>::DLC(const DLC& other): head{nullptr},tail{nullptr}{

    if(other.head==nullptr) return;

    Node* tmp=other.head;
    
    while(tmp!=other.tail){

        insertend(tmp->data);

        tmp=tmp->next;

    }

    insertend(tmp->data);

}

template <typename T>
DLC<T>::DLC(DLC&& other): head{other.head},tail{other.tail}{

    other.head=nullptr;

    other.tail=nullptr;

}

template <typename T>
DLC<T>& DLC<T>::operator=(const DLC& other){

    if(this==&other){

        return *this;

    }

    while(!empty()){

        erasebegin();

    }

    Node* tmp=other.head;

    while(tmp!=other.tail){

        insertend(tmp->data);

        tmp=tmp->next;

    }

    insertend(tmp->data);

    return *this;

}

template <typename T>
DLC<T>& DLC<T>::operator=(DLC&& other){

    if(this==&other){

        return *this;

    }

    Node* tmp=head;

    while(tmp!=tail){

        erasebegin();

        tmp=tmp->next;

    }

    erasebegin();

    head=other.head;

    tail=other.tail;

    other.head=nullptr;

    other.tail=nullptr;

    return *this;

}

template <typename T>
DLC<T>::~DLC(){

    while(!empty()){
    
        erasebegin();

    }

}

template <typename T>
bool DLC<T>::empty() const{

    return head==nullptr;

}

template <typename T>
int DLC<T>::size() const{

    if(head==nullptr) return 0;

    int count=1;

    Node* tmp=head;

    while(tmp!=tail){

        ++count;

        tmp=tmp->next;

    }

    return count;

}

template <typename T>
void DLC<T>::display() const{

    if(head==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    Node* tmp=head;

    while(tmp!=tail){

        std::cout<<tmp->data<<" ";

        tmp=tmp->next;

    }

    std::cout<<tmp->data<<std::endl;

}

template <typename T>
void DLC<T>::insertend(T data){

    Node* newnode=new Node(data);

    if(head==nullptr){

        head=tail=newnode;

        head->next=head;

        head->prev=head;

    }

    else{

        tail->next=newnode;

        newnode->prev=tail;

        newnode->next=head;

        head->prev=newnode;

        tail=newnode;

    }

}

template <typename T>
void DLC<T>::insertbegin(T data){

    Node* newnode=new Node(data);

    if(head==nullptr){

        head=tail=newnode;

        head->next=head;

        head->prev=head;

    }

    else{

        newnode->next=head;

        head->prev=newnode;

        newnode->prev=tail;

        tail->next=newnode;

        head=newnode;

    }

} 

template <typename T>
void DLC<T>::insert(T data,int pos){

    if(pos<1 || pos>size()+1){

        std::cout<<"Invalid position!\n";

        return;

    }

    if(pos==1){
        
        insertbegin(data);

        return;

    }

    if(pos==size()+1){

        insertend(data);

        return;

    }

    int i=1;

    Node* tmp=head;

    Node* newnode=new Node(data);

    while(i<pos-1){

        ++i;

        tmp=tmp->next;

    }

    newnode->next=tmp->next;

    tmp->next->prev=newnode;

    tmp->next=newnode;

    newnode->prev=tmp;

}

template <typename T>
void DLC<T>::erasebegin(){

    if(head==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    if(head==head->next){

        delete head;

        head=tail=nullptr;

        return;

    }

    head=head->next;

    delete tail->next;

    head->prev=tail;

    tail->next=head;

}

template <typename T>
void DLC<T>::eraseend(){

    if(head==nullptr){

        std::cout<<"The list is empty!\n";

        return;

    }

    if(head==head->next){

        delete head;

        head=tail=nullptr;

        return;

    }

    tail=tail->prev;

    delete tail->next;

    head->prev=tail;

    tail->next=head;

}

template <typename T>
void DLC<T>::erase(int pos){

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

    Node* tmp=head;

    int i=1;

    while(i<pos-1){

        tmp=tmp->next;

        i++;

    }

    tmp->next=tmp->next->next;

    delete tmp->next->prev;

    tmp->next->prev=tmp; 

}

template <typename T>
void DLC<T>::reverse(){

    Node* prev=tail;

    Node* current=head;;

    Node* next=current->next;

    while(current!=tail){

        current->next=prev;

        current->prev=next;

        prev=current;

        current=next;

        next=next->next;

    }

    current->next=prev;

    current->prev=next;

    current=tail;

    tail=head;

    head=current;

}

#endif