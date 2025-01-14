#include "BSNode.h"
#include <iostream>

using std::cout;
BSNode::BSNode(const std::string& text)
{
    _data = text;
    _left = nullptr;
    _right = nullptr;
    _count = 0;
}

BSNode::BSNode(const BSNode& other)
{
    _data = other._data;
    _count = other._count;
    _left = (other._left != nullptr) ? new BSNode(*other._left) : nullptr;
    _right = (other._right != nullptr) ? new BSNode(*other._right) : nullptr;
}

BSNode::~BSNode()
{
    delete _left;
    delete _right;
}

void BSNode::insert(const std::string& value)
{
    if (value == _data)
    {
        _count++;
    }
    else if (value < _data)
    {
        if (_left != nullptr)
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
        if (_right != nullptr)
        {
            _right->insert(value);
        }
        else
        {
            _right = new BSNode(value);
        }
    }
}

BSNode& BSNode::operator=(const BSNode& other)
{
    if (this == &other)
    {
        return *this;
    }

    delete _left;
    delete _right;

    _data = other._data;
    _count = other._count;

    _left = (other._left != nullptr) ? new BSNode(*other._left) : nullptr;
    _right = (other._right != nullptr) ? new BSNode(*other._right) : nullptr;

    return *this;
}

bool BSNode::isLeaf() const
{
    return _left == nullptr && _right == nullptr;
}

std::string BSNode::getData() const
{
    return _data;
}

BSNode* BSNode::getLeft() const
{
    return _left;
}

BSNode* BSNode::getRight() const
{
    return _right;
}

int BSNode::getCount() const
{
    return _count;
}

bool BSNode::search(const std::string& val) const
{
    if (val == _data)
    {
        return true;
    }
    if (val < _data && _left != nullptr)
    {
        return _left->search(val);
    }
    if (val > _data && _right != nullptr)
    {
        return _right->search(val);
    }
    return false;
}

int BSNode::getHeight() const
{
    if (isLeaf())
    {
        return 0;
    }

    int leftHeight = (_left != nullptr) ? _left->getHeight() : 0;
    int rightHeight = (_right != nullptr) ? _right->getHeight() : 0;

    return 1 + std::max(leftHeight, rightHeight);
}

int BSNode::getDepth(const BSNode& root) const
{
    if (this == &root)
    {
        return 0;
        
    }

    if (_data < root._data && root._left != nullptr)
    {
        return 1 + root._left->getDepth(*this);
    }

    if (_data > root._data && root._right != nullptr)
    {
        return 1 + root._right->getDepth(*this);
    }

    return -1;
}

int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
    if (node == nullptr)
    {
        return -1;
    }

    if (_data == node->_data)
    {
        return 0;
    }

    if (node->_data < _data && _left != nullptr)
    {
        int leftDist = _left->getCurrNodeDistFromInputNode(node);
        if (leftDist != -1)
        {
            return 1 + leftDist;
        }
    }

    if (node->_data > _data && _right != nullptr)
    {
        int rightDist = _right->getCurrNodeDistFromInputNode(node);
        if (rightDist != -1) 
        {
            return 1 + rightDist;
        }
    }

    return -1; 
}

void BSNode::printNodes() const
{
    if (_left != nullptr)
    {
        _left->printNodes();
    }
    std::cout << _data;
    if (_right != nullptr)
    {
        _right->printNodes();
    }
}

