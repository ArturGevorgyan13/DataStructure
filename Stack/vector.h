    #ifndef V_H
    #define V_H
    #include <iostream>

    namespace my_std{

    template <typename T>
    class Vector{

    private:
        int size;
        int cap;
        T* arr;

    public:
        Vector();
        ~Vector();
        Vector(const Vector& other);
        Vector(Vector&& other);
        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other);

    public:
        void push_back(const T& value);
        void pop_back();
        void insert(int index,const T& value);
        void erase(int index);
        void clear();
        int fsize() const;
        int fcap() const;
        void resize();
        void reserve(int newcapacity);
        void shrink_to_fit();
        T& operator[](int index);
        const T& operator[](int index) const;
        T& at(int index);
        const T& at(int index) const;
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        bool empty() const; 

    };

    }

    #include "vector.tpp"

    #endif