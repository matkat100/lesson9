#pragma once
#include <iostream>
using namespace std;

template <typename T> class BSNode 
{
public:
    BSNode(const T& value);               
    BSNode(const BSNode& other);          
    ~BSNode();
    BSNode& operator=(const BSNode& other);
    void insert(const T& value);         
    bool search(const T& value) const;    
    bool isLeaf() const;      
    int getHeight() const;             
    int getDepth(const BSNode& root) const; 
    int getCurrNodeDistFromInputNode(const BSNode* node) const; 
    T getData() const;               
    BSNode* getLeft() const;           
    BSNode* getRight() const;        
    int getCount() const;               
    void printNodes() const;

private:
    T _data;                            
    BSNode* _left;                
    BSNode* _right;                    
    int _count;                   
};

template <typename T> BSNode<T>::BSNode(const T& value) : _data(value), _left(nullptr), _right(nullptr), _count(0) {}

template <typename T> BSNode<T>::BSNode(const BSNode& other)
    : _data(other._data), _count(other._count),
    _left(other._left ? new BSNode(*other._left) : nullptr),
    _right(other._right ? new BSNode(*other._right) : nullptr) {}


template <typename T> BSNode<T>::~BSNode() 
{
    delete _left;
    delete _right;
}

template <typename T> BSNode<T>& BSNode<T>::operator=(const BSNode& other) 
{
    if (this == &other) 
    {
        return *this;
    }
    delete _left;
    delete _right;
    _data = other._data;
    _count = other._count;
    _left = other._left ? new BSNode(*other._left) : nullptr;
    _right = other._right ? new BSNode(*other._right) : nullptr;
    return *this;
}

template <typename T> void BSNode<T>::insert(const T& value) 
{
    if (value == _data) 
    {
        _count++;
    }
    else if (value < _data) 
    {
        if (_left) 
        {
            _left->insert(value);
        }
        else 
        {
            _left = new BSNode(value);
        }
    }
    else 
    {
        if (_right) 
        {
            _right->insert(value);
        }
        else 
        {
            _right = new BSNode(value);
        }
    }
}

template <typename T> bool BSNode<T>::search(const T& value) const 
{
    if (value == _data)
    {
        return true;
    }
    if (value < _data && _left)
    {
        return _left->search(value);
    }
    if (value > _data && _right)
    {
        return _right->search(value);
    }
    return false;
}

template <typename T> bool BSNode<T>::isLeaf() const
{
    return !_left && !_right;
}

template <typename T> int BSNode<T>::getHeight() const
{
    if (isLeaf()) 
    {
        return 0;
    }
    int leftHeight = _left ? _left->getHeight() : 0;
    int rightHeight = _right ? _right->getHeight() : 0;
    return 1 + std::max(leftHeight, rightHeight);
}

template <typename T> int BSNode<T>::getDepth(const BSNode& root) const 
{
    if (this == &root) 
    {
        return 0;
    }
    if (_data < root._data && root._left) 
    {
        return 1 + root._left->getDepth(*this);
    }
    if (_data > root._data && root._right) 
    {
        return 1 + root._right->getDepth(*this);
    }

    return -1;
}

template <typename T> int BSNode<T>::getCurrNodeDistFromInputNode(const BSNode* node) const 
{
    if (!node) 
    {
        return -1;
    }

    if (_data == node->_data) 
    {
        return 0;
    }

    if (node->_data < _data && _left) 
    {
        int leftDist = _left->getCurrNodeDistFromInputNode(node);
        return leftDist != -1 ? 1 + leftDist : -1;
    }

    if (node->_data > _data && _right) 
    {
        int rightDist = _right->getCurrNodeDistFromInputNode(node);
        return rightDist != -1 ? 1 + rightDist : -1;
    }

    return -1;
}

template <typename T> T BSNode<T>::getData() const 
{
    return _data;
}

template <typename T> BSNode<T>* BSNode<T>::getLeft() const 
{
    return _left;
}

template <typename T> BSNode<T>* BSNode<T>::getRight() const 
{
    return _right;
}

template <typename T> int BSNode<T>::getCount() const
{
    return _count;
}

template <typename T> void BSNode<T>::printNodes() const
{
    if (_left != nullptr)
    {
        _left->printNodes();
    }
    cout << _data << " ";  
    if (_right != nullptr)
    {
        _right->printNodes();
    }
}
