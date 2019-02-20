#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "DataContainer.h"

template<typename T>
class LinkedList : public DataContainer<T>
{
    private:
        struct Node
        {
            T value;
            Node* next;
        }; 
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList();
        void PushBack(T) override;
        void PushFront(T) override;
        T& operator[](unsigned int) override;
        ~LinkedList();
};

//definitions

template<typename T>
LinkedList<T>::LinkedList()
    : head(nullptr), tail(nullptr) 
{
    this->size = 0;
}

template<typename T>
void LinkedList<T>::PushBack(T data)
{
    Node *newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;
    if (this->head != nullptr)
    { 
        this->tail->next = newNode;
        this->tail = newNode;
    }
    else
    {
        this->head = newNode;
        this->tail = newNode;
    }
    ++this->size;
}

template<typename T>
void LinkedList<T>::PushFront(T data)
{
    Node *newNode = new Node;
    newNode->value = data;
    if (this->head != nullptr)
    {
        newNode->next = head;
        this->head = newNode;
    }
    else
    {
        this->head = newNode; 
        this->tail = newNode;
    }
    ++this->size;
}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
    if(index < this->size)
    {
        unsigned int nodeCount = 0;
        Node *tempNode = this->head;
        while(nodeCount != index){
        tempNode = tempNode->next;
        ++nodeCount;
        }
        return tempNode->value;
    }
    else
        throw;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node *tempNode = this->head;
    while(tempNode != nullptr)
    {
        tempNode = tempNode->next;
        delete this->head;
        this->head = tempNode;
    }
}


#endif