#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

template<typename T> 
class DataContainer
{
    protected:
        unsigned int size;
    public:
        virtual void PushBack(T data) = 0;
        virtual void PushFront(T data) = 0;
        virtual T& operator[](unsigned int index) = 0;
        unsigned int Size() const;
}; 

//definitions

template<typename T>
unsigned int DataContainer<T>::Size() const
{
    return this->size;
}



#endif