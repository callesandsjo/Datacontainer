#include "LinkedList.h"
#include "DataContainer.h"
template<typename T>
LinkedList<T>::LinkedList()
    : head(NULL), tail(NULL), size(0)
{
}

template<typename T>
void LinkedList<T>::PushBack(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->value = data;
    newNode->next = NULL;
    if (this->head == NULL)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    ++this->size;
}

template<typename T>
void LinkedList<T>::PushFront(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->value = data;
    if (this->head == NULL)
        this->head = newNode;
    else
    {
        newNode->next = head;
        this->head = newNode;
    }
    ++this->size;
}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
    unsigned int nodeCount = 0;
    Node<T> *tempNode = this->head;
    while(nodeCount != index){
        tempNode = tempNode->next;
        ++nodeCount;
    }
    return tempNode->value;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *tempNode = this->head;
    while(tempNode != nullptr)
    {
        tempNode = tempNode->next;
        delete this->head;
        this->head = tempNode;
    }
}

template class LinkedList<int>;
template class LinkedList<std::string>;
