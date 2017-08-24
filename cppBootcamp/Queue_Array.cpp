//
//  Queue.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include "Queue_Array.hpp"

void Queue_Array::enqueue(int value){
    
    if(this->isFull())
        return;
    printf("Adding value %d to index %d\n",value,m_back & m_size);
    m_stroge[m_back % m_size] = value;
    m_back++;
    m_numOfElemnets++;
}
int Queue_Array::dequeue(){
    if(this->isEmpty())
        return -1;
    
    int value = m_stroge[m_front % m_size];
    printf("Removing value %d from index %d\n",value,m_front % m_size);
    m_front++;
    m_numOfElemnets++;
    return value;
}

bool Queue_Array::isFull(){
    if(m_numOfElemnets >=  m_size)
        return  true;
    return false;
}
bool Queue_Array::isEmpty(){
    if(m_numOfElemnets == 0)
        return true;
    return false;
}
int Queue_Array::peak(){
    if(this->isEmpty())
        return -1;
    return m_stroge[m_front % m_size];
}

