#include "listdouble.h"

template <typename T>
my_std::Node<T>::Node(): data{},next{nullptr},prev{nullptr}{}

template <typename T>
my_std::Node<T>::Node(T data): data{data},next{nullptr},prev{nullptr}{}

template <typename T>
T my_std::Node<T>::getdata(){

    return data;

}

template <typename T>
my_std::Node<T>* my_std::Node<T>::getnext(){

    return next;

}

template <typename T>
my_std::Node<T>* my_std::Node<T>::getprev(){

    return prev;

}

template <typename T>
void my_std::Node<T>::setdata(T newdata){

    data=newdata;

}

template <typename T>
void my_std::Node<T>::setnext(Node<T>* newnext){

    next=newnext;

}

template <typename T>
void my_std::Node<T>::setprev(Node<T>* newprev){

    prev=newprev;

}

template <typename T>
my_std::List<T>::List(): head{nullptr},tail{nullptr}{}

template <typename T>
my_std::List<T>::~List(){

    clear();

}

template <typename T>
my_std::List<T>::List(const List<T>& other){

    if(other.head==nullptr){

        head=tail=nullptr;

        return;

    }

    head=new Node<T>(other.head->getdata());

    Node<T>* src=other.head->getnext();

    Node<T>* dest=head;

    while(src!=nullptr){

        Node<T>* newnode=new Node<T>(src->getdata());

        dest->setnext(newnode);

        newnode->setprev(dest);

        dest=newnode;

        src=src->getnext();

    }

    tail=dest;

}

template <typename T>
my_std::List<T>::List(List<T>&& other): head{other.head},tail{other.tail}{

     other.head=nullptr;

     other.tail=nullptr;

}

template <typename T>
my_std::List<T>& my_std::List<T>::operator=(const List& other){

    if(this==&other) return *this;

    this->clear();

    if(other.head==nullptr){

        head=tail=nullptr;

        return *this;

    }

    head=new Node<T>(other.head->getdata());

    Node<T>* src=other.head->getnext();

    Node<T>* dest=head;

    while(src!=nullptr){

        Node<T>* newnode=new Node<T>(src->getdata());

        dest->setnext(newnode);

        newnode->setprev(dest);

        dest=newnode;

        src=src->getnext();

    }

    tail=dest;

    return *this;

}

template <typename T>
my_std::List<T>& my_std::List<T>::operator=(List<T>&& other){

    if(this==&other){

        return *this;

    }

    if(other.head==nullptr){

        head=tail=nullptr;

        return *this;

    }

    this->clear();

    head=other.head;

    tail=other.tail;

    other.head=nullptr;

    other.tail=nullptr;

    return *this;

}

template <typename T>
void my_std::List<T>::clear(){

    while(head!=nullptr){

        Node<T>* tmp=head;

        head=head->getnext();

        delete tmp;

    }

    tail=nullptr;

}

template <typename T>
bool my_std::List<T>::isempty() const{

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
my_std::Node<T>* my_std::List<T>::search(const T& value){

    Node<T>* current=head;

    while(current!=nullptr && current->getdata()!=value){

        current=current->getnext();

    }

    if(current==nullptr){

        return nullptr;

    }

    return current;

}

template <typename T>
void my_std::List<T>::displayforward(){

    Node<T>* current=head;

    while(current!=nullptr){

        std::cout<<current->getdata()<<std::endl;

        current=current->getnext();

    }

}

template <typename T>
void my_std::List<T>::displaybackward(){

    Node<T>* current=tail;

    while(current!=nullptr){

        std::cout<<current->getdata()<<std::endl;

        current=current->getprev();

    }
}

template <typename T>
void my_std::List<T>::inserttail(const T& value){

    Node<T>* newnode=new Node<T>(value);

    if(head==nullptr){

        head=newnode;

        tail=newnode;

        return;

    }

    tail->setnext(newnode);

    newnode->setprev(tail);

    tail=newnode;

}

template <typename T>
void my_std::List<T>::inserthead(const T& value){

    Node<T>* newnode=new Node<T>(value);

    if(head==nullptr){

        head=newnode;

        tail=newnode;

        return;

    }

    newnode->setnext(head);

    head->setprev(newnode);

    head=newnode;

}

template <typename T>
void my_std::List<T>::insertposition(int pos,const T& value){

    if(pos<=0) return;

    int count=1;

    Node<T>* current=head;

    if(pos==1){

        inserthead(value);

        return;

    }

    while(current->getnext()!=nullptr){

        if(count==pos-1){

            Node<T>* newnode=new Node<T>(value);

            newnode->setnext(current->getnext());

            current->getnext()->setprev(newnode);

            current->setnext(newnode);

            newnode->setprev(current);

            return;

        }

        current=current->getnext();

        count++;

    }

    inserttail(value);

    return;

}

template <typename T>
void my_std::List<T>::deletehead(){

    if(head==nullptr) return;

    Node<T>* tmp=head;

    if(head==tail){

        head=nullptr;

        tail=nullptr;

    }

    else{

        head=head->getnext();

        head->setprev(nullptr);

    }

    delete tmp; 

}

template <typename T>
void my_std::List<T>::deletetail(){

    if(tail==nullptr){

        return;

    }

    Node<T>* tmp=tail;

    if(head==tail){

        head=nullptr;

        tail=nullptr;

    }

    else{

        tail=tail->getprev();

        tail->setnext(nullptr);

    }

    delete tmp;

}   

template <typename T>
void my_std::List<T>::deleteposition(int pos){

    if(pos<=0) return;

    int count=1;

    if(pos==1){

        deletehead();

    }    

    Node<T>* current=head;

    while(current!=nullptr && count<pos){

        current=current->getnext();

        count++;

    }

    if(current==nullptr) return;

    if(current->getnext()==nullptr){

        deletetail();

        return;

    }

    Node<T>* tmp=current;

    current->getnext()->setprev(current->getprev());

    current->getprev()->setnext(current->getnext());

    delete tmp;

}