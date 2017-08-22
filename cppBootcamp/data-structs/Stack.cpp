//
//  Stack.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include "Stack.hpp"
#include <iostream>
using namespace std;
bool Stack::isEmplty(){
    
    if( m_numOfElemets == 0)
        return true;
    
    return  false;
}

void Stack::push(int value){
    
    if(m_numOfElemets > m_size)
        return;
    
    m_storage[m_numOfElemets] = value;
    m_numOfElemets++;
}

int  Stack::pop(){
    if(this->isEmplty())
        return  -1;
    
    int value = m_storage[m_numOfElemets-1];
    m_numOfElemets--;
    return value;
}
int Stack::peak(){
    if(this->isEmplty())
        return  -1;
    
    return m_storage[m_numOfElemets-1];
}

void Stack:: display(){
    for (int i = 0 ; i < m_numOfElemets ; i++)
        cout << m_storage[i] << "\t";
    cout <<"\n";
}
