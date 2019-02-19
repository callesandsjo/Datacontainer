#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

#include <string>
#include <iostream>

template<typename T> 
class DataContainer
{
    protected:
     
    public:
        virtual void PushBack(T data) = 0;
        virtual void PushFront(T data) = 0;
        virtual T& operator[](unsigned int index) = 0;


};



#endif