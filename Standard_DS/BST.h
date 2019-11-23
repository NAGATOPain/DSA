#ifndef DS_BST
#define DS_BST

template <typename T>
struct Node{

    T value;
    Node *left, *right;

    Node(): left(nullptr), right(nullptr){}
    Node(const T& val): value(val), left(nullptr), right(nullptr){}
    Node(const T& val, Node* l, Node* r): value(val), left(l), right(r){}

};

template<typename T>
class BST {

    Node<T>* root;

public:

    BST();
    ~BST();

    void insert(const T&);
    T& search(bool (*)(const T&));
    void remove(const T&);

    void clear();

    void print();
};

template<typename T>
BST<T>::BST(){
    root = nullptr;
}

template<typename T>
BST<T>::~BST(){
    clear();
}

template<typename T>
void BST<T>::insert(const T& val){

}

template<typename T>
T& BST<T>::search(bool (*compare)(const T&)){

}

template<typename T>
void BST<T>::remove(const T& val){

}

template<typename T>
void BST<T>::clear(){

}

template<typename T>
void BST<T>::print(){

}

#endif