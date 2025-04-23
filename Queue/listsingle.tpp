#include "listsingle.h"

template <typename T>
my_std::Node<T>::Node(): data{},next{nullptr}{}

template <typename T>
my_std::Node<T>::Node(T data): data{data},next{nullptr}{}

template <typename T>
T my_std::Node<T>::getdata(){

    return data;

}

template <typename T>
my_std::Node<T>* my_std::Node<T>::getnext() const{

    return next;

}

template <typename T>
void my_std::Node<T>::setnext(Node<T>* node){

    next=node;

}

template <typename T>
void my_std::Node<T>::setdata(T dat){

    data=dat;

}

template <typename T>
my_std::List<T>::List(): head{nullptr}{}

template <typename T>
my_std::List<T>::~List(){

    Node<T>* current=head;

    while(current!=nullptr){

        Node<T>* tmp=current;

        current=current->getnext();

        delete tmp;

    }

}

template <typename T>
my_std::List<T>::List(const List& other){

    if(other.head==nullptr) return;

    head=new Node<T>(other.head->getdata());

    Node<T>* src=(other.head)->getnext();

    Node<T>* dest=head;

    while(src!=nullptr){

        dest->setnext(new Node<T>(src->getdata()));

        dest=dest->getnext();

        src=src->getnext();

    }

}

template <typename T>
my_std::List<T>::List(List&& other): head{other.head}{

    other.head=nullptr;

}

template <typename T>
my_std::List<T>& my_std::List<T>::operator=(const List& other){

    if(this==&other) return *this;

    this->clear();

    if(other.head==nullptr){

        head=nullptr;

        return *this;

    }

    head=new Node<T>(other.head->getdata());
    
    Node<T>* src=other.head->getnext();

    Node<T>* dest=head;

    while(src!=nullptr){

        dest->setnext(new Node<T>(src->getdata()));

        src=src->getnext();

        dest=dest->getnext();

    }

    return *this;

}

template <typename T>
my_std::List<T>& my_std::List<T>::operator=(List&& other){

    if(this==&other) return *this;

    this->clear();

    head=other.head;

    other.head=nullptr;

    return *this;

}

template <typename T>
bool my_std::List<T>::empty() const{

    return head==nullptr;

}

template <typename T>
int my_std::List<T>::size() const{

    int count=0;

    Node<T>* current=head;

    while(current!=nullptr){

        count++;

        current=current->getnext();

    }

    return count;

}

template <typename T>
void my_std::List<T>::push_front(const T& value){

    Node<T>* newnode=new Node<T>(value);

    newnode->setnext(head);

    head=newnode;

}

template <typename T>
void my_std::List<T>::pop_front(){

    if(head==nullptr) return;

    Node<T>* tmp=head;

    head=head->getnext();

    delete tmp;

}

template <typename T>
void my_std::List<T>::push_back(const T& value){

    Node<T>* newnode=new Node<T>(value);

    if(head==nullptr){

        head=newnode;

        return;

    }

    Node<T>* current=head;

    while(current->getnext()!=nullptr){

        current=current->getnext();

    }

    current->setnext(new Node<T>(value));

}

template <typename T>
T my_std::List<T>::front(){

    if(head==nullptr) throw std::out_of_range("Error!");

    return head->getdata();

}

template <typename T>
T my_std::List<T>::back(){

    if(head==nullptr) throw std::out_of_range("Error!");

    Node<T>* current=head;

    while(current->getnext()!=nullptr){

        current=current->getnext();

    }

    return current->getdata();

}

template <typename T>
void my_std::List<T>::clear(){

    while(head!=nullptr){

        Node<T>* tmp=head;

        head=head->getnext();

        delete tmp;

    }

}

template <typename T>
my_std::Node<T>* my_std::List<T>::find(const T& value){

    Node<T>* current=head;

    while(current!=nullptr){

        if(current->getdata()==value){

            return current;

        }

        current=current->getnext();

    }

    return nullptr;

}

template <typename T>
void my_std::List<T>::insert(Node<T>* node,const T& value){

    Node<T>* current=head;

    while(current!=nullptr && current!=node){

        current=current->getnext();

    }

    if(current==nullptr) return;

    Node<T>* newnode=new Node<T>(value);

    newnode->setnext(current->getnext());

    current->setnext(newnode);

}

template <typename T>
void my_std::List<T>::erase(Node<T>* node){

    Node<T>* current=head;

    while(current!=node && current!=nullptr){

        current=current->getnext();

    }

    if(current==nullptr || current->getnext()==nullptr) return;

    Node<T>* tmp=current->getnext();

    current->setnext(current->getnext()->getnext());

    delete tmp;

}

template <typename T>
void my_std::List<T>::reverse(){

    Node<T>* prev=nullptr;

    Node<T>* current=head;

    Node<T>* next=nullptr;

    while(current!=nullptr){

        next=current->getnext();

        current->setnext(prev);

        prev=current;

        current=next;

    } 

    head=prev;

}

template <typename T>
void my_std::List<T>::merge(List& other){

    if(other.head==nullptr) return;

    Node<T>* current=head;

    if(current==nullptr){

        head=other.head;

        return;

    }

    while(current->getnext()!=nullptr){

        current=current->getnext();

    }

    current->setnext(other.head);

    other.head=nullptr;

}