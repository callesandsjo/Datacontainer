//#include "DataContainer.h"
#include "Vector.h"
#include "DataContainer.h"

template<typename T>
Vector<T>::Vector()
    : capacity(4), size(0)
{
    this->container = new T[capacity];
}

template<typename T>
void Vector<T>::PushBack(T data)
{
    if(size >= capacity)
        Resize(capacity*2);
    this->container[size] = data;
    ++this->size;
}

template<typename T>
void Vector<T>::PushFront(T data)
{
    if(size >= capacity)
        Resize(capacity*2);
    T elementToMove1 = this->container[0];
    T elementToMove2;
    this->container[0] = data;
    for(unsigned int i = 1; i <= this->size; i++)
    {
        if(i != this->size){
            elementToMove2 = this->container[i];
            this->container[i] = elementToMove1;
            elementToMove1 = elementToMove2;
        }
        else
            this->container[i] = elementToMove1;  
    }
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
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] this->container;
}

template class Vector<int>;
template class Vector<std::string>;