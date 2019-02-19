#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "DataContainer.h"
#include <string>

template<typename T>
struct Node 
        {
            T value;
            Node<T>* next;
        };

template<typename T>
class LinkedList : public DataContainer<T>
{
    private:
        Node<T>* head;
        Node<T>* tail;
        unsigned int size;
    public:
        LinkedList();
        void PushBack(T) override;
        void PushFront(T) override;
        T& operator[](unsigned int) override;
        ~LinkedList();
};



#endif