//
//  Stack.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>


class Stack{
    
public:
    
    Stack(int size)
    {
        m_size = size;
        m_storage = new int[size];
        m_numOfElemets = 0;
    }
    ~Stack()
    {
        delete m_storage;
    }
    
    void push(int value);
    int pop();
    int peak();
    bool isEmplty();
    
    void display();
private:
    
    int m_numOfElemets;
    int m_size;
    int *m_storage;
    
    
    
};

#endif /* Stack_hpp */
