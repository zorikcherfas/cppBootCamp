//
//  LinkedList.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

struct node
{
    int data;
    node *next;
};

class LinkedList{
    
public:
    LinkedList()
    {
        m_tail = nullptr;
        m_head = nullptr;
        m_counter = 0;
        
    }
    void display();
    void createNode(int value);
    void insertFromTheEnd(int value);
    void insertFromTheStart(int value);
    void insert_position(int value, int position);
    
    void delete_last();
    void delete_first();
    void delete_position(int position);
private:
    node *m_tail;
    node *m_head;
    int m_counter;
};

#endif /* LinkedList_hpp */
