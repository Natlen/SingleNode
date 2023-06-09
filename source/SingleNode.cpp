#include "SingleNode.h"
#include <iostream>
template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode() : 
    m_pData(nullptr),
    m_pNext(nullptr) 
{ std::cout << "constructor" << std::endl; };

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(T a_data) : 
    m_pData(new T(a_data)), 
    m_pNext(nullptr) 
{ std::cout << "constructor" << std::endl; };

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(const SingleNode<T>& a_node) : 
    m_pData(nullptr == a_node.m_pData ? nullptr : new T(*a_node.m_pData)), 
    m_pNext(nullptr == a_node.m_pNext ? nullptr : new SingleNode<T>(*a_node.m_pNext)) 
{ std::cout << "copy constructor" << std::endl; };

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(SingleNode<T>&& a_node) : 
    m_pData(a_node.m_pData), 
    m_pNext(a_node.m_pNext)
{
    a_node.m_pData = nullptr;
    a_node.m_pNext = nullptr;
     std::cout << "move constructor" << std::endl;
};

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::~SingleNode() 
{
    delete m_pData;
    delete m_pNext;
    m_pData = nullptr;
    m_pNext = nullptr;
     std::cout << "distructor" << std::endl;
};

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>& NATLEN::DATA_STRUCTURES::SingleNode<T>::operator =(const SingleNode<T>& a_node)
{
    SingleNode<T>* newNode = new SingleNode<T>(a_node);
    delete m_pData;
    delete m_pNext;
    m_pData = nullptr == newNode->m_pData ? nullptr : new T(*newNode->m_pData);
    m_pNext = nullptr == newNode->m_pNext ? nullptr : new SingleNode<T>(*newNode->m_pNext);
    std::cout << "operator = &" << std::endl;
    return *this;
     
};

template<typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>& NATLEN::DATA_STRUCTURES::SingleNode<T>::operator =(SingleNode<T>&& a_node)
{
    m_pData = a_node.m_pData;
    m_pNext = a_node.m_pNext;
    a_node.m_pData = nullptr;
    a_node.m_pNext = nullptr;
    std::cout << "operator = &&" << std::endl;
    return *this;
      
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>& NATLEN::DATA_STRUCTURES::SingleNode<T>::operator +(const SingleNode<T>& a_node)
{
    SingleNode<T>* connectedNode = nullptr == this ? new SingleNode<T>() : new SingleNode<T>(*this);
    connectedNode->m_pNext = new SingleNode<T>(a_node);
    std::cout << "operator +" << std::endl;
    return *connectedNode;
      
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>& NATLEN::DATA_STRUCTURES::SingleNode<T>::operator +(SingleNode<T>&& a_node)
{
    m_pNext = &a_node;
    std::cout << "operator + &&" << std::endl;
    return *this;
      
};

template class NATLEN::DATA_STRUCTURES::SingleNode<int>;