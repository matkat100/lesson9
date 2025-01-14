#pragma once

#include <string>

/////////////////////////////////////////////
//       GenericNode Definition            //
//                                         //
// Please note: the definitions and        //
// implementations are in the same file    //
// because we use templates                //
//                                         //
/////////////////////////////////////////////

template <class T>
class GenericNode {
public:
    GenericNode(const T& item);

    // Getters
    GenericNode<T>* get_next() const;
    T& get_item();

    // Setters
    void set_next(GenericNode<T>* next);
    void set_item(const T& new_item);

private:
    T _item;                        // The item stored in the node
    GenericNode<T>* _next;          // Pointer to the next node
};

/////////////////////////////////////////////
//       GenericList Definition            //
//                                         //
// Please note: the definitions and        //
// implementations are in the same file    //
// because we use templates                //
//                                         //
/////////////////////////////////////////////

template <class T>
class GenericList {
public:
    GenericList();
    ~GenericList();

    // Getters
    GenericNode<T>* get_first() const;

    // Setters
    void set_first(GenericNode<T>* first);

    // Adds an object of type T to the end of the list
    void add(const T& device_to_add);

private:
    GenericNode<T>* _first;         // Pointer to the first node in the list
};

/////////////////////////////////////////////
//       GenericNode Implementation        //
//                                         //
/////////////////////////////////////////////

template <class T>
GenericNode<T>::GenericNode(const T& item) {
    this->_item = item;
    this->_next = nullptr;
}

template <class T>
GenericNode<T>* GenericNode<T>::get_next() const {
    return this->_next;
}

template <class T>
T& GenericNode<T>::get_item() {
    return this->_item;
}

template <class T>
void GenericNode<T>::set_next(GenericNode<T>* next) {
    this->_next = next;
}

template <class T>
void GenericNode<T>::set_item(const T& new_item) {
    this->_item = new_item;
}

/////////////////////////////////////////////
//       GenericList Implementation        //
//                                         //
/////////////////////////////////////////////

template <class T>
GenericList<T>::GenericList() {
    this->_first = nullptr;
}

template <class T>
GenericList<T>::~GenericList() {
    GenericNode<T>* temp;
    while (this->_first != nullptr) { // While the list is not empty
        temp = this->_first;          // Temporary pointer to the first element
        this->_first = this->_first->get_next(); // Move the first pointer to the next element
        delete temp;                  // Delete the previous first element
    }
}

template <class T>
GenericNode<T>* GenericList<T>::get_first() const {
    return this->_first;
}

template <class T>
void GenericList<T>::set_first(GenericNode<T>* first) {
    this->_first = first;
}

template <class T>
void GenericList<T>::add(const T& device_to_add) {
    // Create a new node to store the object
    GenericNode<T>* new_node = new GenericNode<T>(device_to_add);

    if (this->_first == nullptr) { // If the list is empty
        this->_first = new_node;   // The new node is the first node
    }
    else {                       // The list has at least one element
        GenericNode<T>* curr = this->_first; // Start from the first node
        while (curr->get_next() != nullptr) { // Traverse to the last node
            curr = curr->get_next();
        }
        curr->set_next(new_node); // Add the new node at the end
    }
}
