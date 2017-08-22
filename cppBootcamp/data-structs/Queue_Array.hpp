//
//  Queue.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

class Queue_Array{
    
    int *m_stroge;
    int m_size;
    int m_numOfElemnets;
    int m_front;
    int m_back;
    
public:
    Queue_Array(int size)
    {
        m_size = size;
        m_stroge = new int[size];
        m_front = 0;
        m_back = 0;
    }
    ~Queue_Array()
    {
        delete m_stroge;
    }
    
    void enqueue(int value); // add item to queue
    int dequeue(); // remove item from queue
    
    int peak();
    bool isFull();
    bool isEmpty();
    
    
};
#endif /* Queue_hpp */
