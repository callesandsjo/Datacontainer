#ifndef VECTOR_H
#define VECTOR_H
#include "DataContainer.h"
#include <string>
#include <iostream>

template<typename T>
class Vector : public DataContainer<T>
{
    private:
        unsigned int capacity;
        unsigned int size;
        T *container;
        
          
    public:
        Vector();
        void PushBack(T) override;
        void PushFront(T) override;
        void Resize(unsigned int);
        T& operator[](unsigned int) override;
        ~Vector();
};



#endif