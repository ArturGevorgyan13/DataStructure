    #ifndef RBT_H
    #define RBT_H
    #include <iostream>
    #include <queue>

    enum class Color{RED,BLACK};

    template <typename T>
    class Node{

    public:
        T data;
        Node<T>* parent;
        Node<T>* left;
        Node<T>* right;
        Color color;

    public:
        Node();
        Node(T val);

    };

    template <typename T>
    class RBT{

    private:
        Node<T>* root;
        Node<T>* nil;

    private:
        void rotateLeft(Node<T>* node);
        void rotateRight(Node<T>* node);
        void fixInsertion(Node<T>* node);
        void fixDeletion(Node<T>* node);
        void transplant(Node<T>*,Node<T>*);
        Node<T>* findMin(Node<T>* node) const;
        Node<T>* findMax(Node<T>* node) const;
        void deleteNode(Node<T>* node);
        void clear(Node<T>* node);
        void inorderTraversal(Node<T>* node);
        void levelorderTraversal(Node<T>* node);

    public:
        RBT();
        ~RBT();
        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value) const;
        T getMin() const;
        T getMax() const;
        bool isEmpty() const;
        void clear();
        void inorderTraversal();
        void levelorderTraversal();

    };

    #endif