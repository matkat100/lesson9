#pragma once

#include <string>

template <class T> class GenericNode 
{
public:
    GenericNode(const T& item);
    GenericNode<T>* get_next() const;
    T& get_item();
    void set_next(GenericNode<T>* next);
    void set_item(const T& new_item);

private:
    T _item;    
    GenericNode<T>* _next;       
};

template <class T> class GenericList 
{
public:
    GenericList();
    ~GenericList();
    GenericNode<T>* get_first() const;
    void set_first(GenericNode<T>* first);
    void add(const T& device_to_add);

private:
    GenericNode<T>* _first;
};

template <class T> GenericNode<T>::GenericNode(const T& item) 
{
    this->_item = item;
    this->_next = nullptr;
}

template <class T> GenericNode<T>* GenericNode<T>::get_next() const 
{
    return this->_next;
}

template <class T> T& GenericNode<T>::get_item() 
{
    return this->_item;
}

template <class T> void GenericNode<T>::set_next(GenericNode<T>* next) 
{
    this->_next = next;
}

template <class T> void GenericNode<T>::set_item(const T& new_item) 
{
    this->_item = new_item;
}

template <class T> GenericList<T>::GenericList() 
{
    this->_first = nullptr;
}

template <class T> GenericList<T>::~GenericList() 
{
    GenericNode<T>* temp;
    while (this->_first != nullptr) 
    { 
        temp = this->_first;       
        this->_first = this->_first->get_next(); 
        delete temp;                
    }
}

template <class T> GenericNode<T>* GenericList<T>::get_first() const 
{
    return this->_first;
}

template <class T> void GenericList<T>::set_first(GenericNode<T>* first) 
{
    this->_first = first;
}

template <class T> void GenericList<T>::add(const T& device_to_add) 
{
    GenericNode<T>* new_node = new GenericNode<T>(device_to_add);

    if (this->_first == nullptr)
    { 
        this->_first = new_node;
    }
    else 
    {                       
        GenericNode<T>* curr = this->_first; 
        while (curr->get_next() != nullptr) 
        { 
            curr = curr->get_next();
        }
        curr->set_next(new_node); 
    }
}
