#include "vector.h"

template <typename T>
my_std::Vector<T>::Vector(): size{0},cap{1},arr{new T[cap]}{}

template <typename T>
my_std::Vector<T>::~Vector(){

    delete[] arr;

}

template <typename T>
my_std::Vector<T>::Vector(const Vector& other): size{other.size},cap{other.cap},arr{new T[cap]}{

    for(int i=0;i<size;i++){

        arr[i]=other.arr[i];

    }

}

template <typename T>
my_std::Vector<T>::Vector(Vector&& other): size{other.size},cap{other.cap},arr{other.arr}{

    other.arr=nullptr;

    other.size=0;

    other.cap=0;

}

template <typename T>
my_std::Vector<T>& my_std::Vector<T>::operator=(const Vector& other){

    if(this==&other) return *this;

    delete[] arr;

    size=other.size;

    cap=other.cap;

    arr=new T[cap];

    for(int i=0;i<size;i++){

        arr[i]=other.arr[i];

    }

    return *this;

}

template <typename T>
my_std::Vector<T>& my_std::Vector<T>::operator=(Vector&& other){

    if(this==&other) return *this;

    delete[] arr;

    size=other.size;

    cap=other.cap;

    arr=other.arr;

    other.arr=nullptr;

    other.size=0;

    other.cap=0;

    return *this;

}

template <typename T>
void my_std::Vector<T>::push_back(const T& value){

    if(size==cap) resize();

    arr[size]=value;

    size++;

}

template <typename T>
void my_std::Vector<T>::pop_back(){

    if(!size) return;

    size--;

}

template <typename T>
void my_std::Vector<T>::insert(int index,const T& value){

    if(index<0 || index>size) throw std::out_of_range("The index is out of range!");

    if(size==cap) resize();

    for(int i=size;i>index;i--){

        arr[i]=arr[i-1];

    }

    arr[index]=value;

    size++;

}

template <typename T>
void my_std::Vector<T>::erase(int index){

    if(index<0 || index>=size) throw std::out_of_range("The index is out of range!");

    for(int i=index;i<size-1;i++){

        arr[i]=arr[i+1];

    }

    size--;

}

template <typename T>
void my_std::Vector<T>::clear(){

    size=0;

}

template <typename T>
int my_std::Vector<T>::fcap() const{

    return cap;

}

template <typename T>
int my_std::Vector<T>::fsize() const{

    return size;

}

template <typename T>
void my_std::Vector<T>::resize(){

    cap=cap*2;

    T* tarr=new T[cap];

    for(int i=0;i<size;i++){

        tarr[i]=arr[i];

    } 

    delete[] arr;

    arr=tarr;

}

template <typename T>
void my_std::Vector<T>::reserve(int newcap){

    if(newcap>cap){

        cap=newcap;

        T* tarr=new T[cap];

        for(int i=0;i<size;i++){
    
            tarr[i]=arr[i];

        }

        delete[] arr;

        arr=tarr;

    }

}

template <typename T>
void my_std::Vector<T>::shrink_to_fit(){

    if(size==cap) return;

    cap=size;

    T* tarr=new T[cap];

    for(int i=0;i<cap;i++){
    
        tarr[i]=arr[i];

    }

    delete[] arr;

    arr=tarr;

}

template <typename T>
T& my_std::Vector<T>::operator[](int index){

    return arr[index];

}

template <typename T>
const T& my_std::Vector<T>::operator[](int index) const{

    return arr[index];

}

template <typename T>
T& my_std::Vector<T>::at(int index){

    if(index<0 || index>=size) throw std::out_of_range("The index is out of range!");

    return arr[index];

}

template <typename T>
const T& my_std::Vector<T>::at(int index) const{

    if(index<0 || index>=size) throw std::out_of_range("The index is out of range!");

    return arr[index];

}

template <typename T>
T& my_std::Vector<T>::front(){

    if(size==0) throw std::out_of_range("No element!");

    return arr[0];

}

template <typename T>
T& my_std::Vector<T>::back(){

    if(size==0) throw std::out_of_range("No element!");

    return arr[size-1];

}

template <typename T>
bool my_std::Vector<T>::empty() const{

    return size==0;

}