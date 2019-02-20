#ifndef VECTOR_H
#define VECTOR_H
#include "DataContainer.h"


template<typename T>
class Vector : public DataContainer<T>
{
    private:
        void Resize(unsigned int);
        unsigned int capacity;
        T *container;
        
           
    public:
        Vector();
        void PushBack(T) override;
        void PushFront(T) override;
        T& operator[](unsigned int) override;
        ~Vector();
};

//definitions

template<typename T>
Vector<T>::Vector()
    : capacity(4)
{
    this->container = new T[capacity];
    this->size = 0;
}

template<typename T>
void Vector<T>::PushBack(T data)
{
    if(this->size >= this->capacity)
        Resize(this->capacity*2);
    this->container[this->size] = data;
    ++this->size;
}

template<typename T>
void Vector<T>::PushFront(T data)
{
    
    if(this->size >= capacity)
        Resize(capacity*2);
    for(unsigned int i = this->size; i > 0; i--) //moving everything one step forward from the back
    {
        this->container[i] = this->container[i-1];
    }
    this->container[0] = data;
    ++this->size;
}

template<typename T>
void Vector<T>::Resize(unsigned int newCapacity)
{
    T* newContainer = new T[newCapacity];
    for(unsigned int i = 0; i < this->size; i++)
        newContainer[i] = this->container[i];
    delete[] this->container;
    this->container = newContainer;
    this->capacity = newCapacity;
}

template<typename T>
T& Vector<T>::operator[](unsigned int index)
{
    if(index < this->size)
        return this->container[index];
    else 
        throw;
}


template<typename T>
Vector<T>::~Vector()
{
    delete[] this->container;
}



#endif