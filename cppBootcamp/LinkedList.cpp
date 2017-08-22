//
//  LinkedList.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include "LinkedList.hpp"
#include "iostream"
using namespace std;


void LinkedList:: createNode(int value)
{
        node *temp = new node;
        temp->data = value;
        temp->next = nullptr;
        
        if(m_head == nullptr)
        {
            m_head = temp;
            m_tail = temp;
            temp = nullptr;
            m_counter++;
            
        }
        else
        {
            m_tail->next = temp;
            m_tail = temp;
            m_counter++;
        }
        
}

void LinkedList::display(){
    
    node *temp = m_head;
    
    while(temp)
    {
        cout << temp->data <<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}


void LinkedList::insertFromTheStart(int value){
    
    node *temp = new node;
    temp->data = value;
    temp->next = m_head;
    
    // update the head
    m_head = temp;
}

void LinkedList::insertFromTheEnd(int value){
    
    node *temp = new node;
    
    temp->data = value;
    temp->next = nullptr;
    
    m_tail->next = temp;
    m_tail = temp;
    
}

void LinkedList::insert_position(int value, int position){
    
    node *temp = new node;
    node *pCurrent = m_head;
    node *prev  = nullptr;
    temp->data = value;
    temp->next = nullptr;
    
    
    int currentPosition = 1;
    
    
    while(pCurrent){
        prev = pCurrent;
        pCurrent = pCurrent->next;
        if(currentPosition == position)
            break;
        currentPosition++;
    }
    prev->next = temp;
    temp->next = pCurrent;
    
}

void LinkedList::delete_last()
{
    node *currentNode = nullptr;
    node *prvNode = nullptr;
    
    currentNode = m_head;
    
    while(currentNode->next) {
        prvNode = currentNode;
        currentNode = currentNode->next;
    }
    prvNode->next = nullptr;
    m_tail = prvNode;
    delete currentNode;
    
}

void LinkedList::delete_first()
{
    node *currentNode;
    node *nextNode;
    
    currentNode = m_head;
    nextNode = m_head->next;
    
    m_head = nextNode;
    delete currentNode;
}
void LinkedList::delete_position(int position)
{
    node *currentNode = m_head;
    node *nextNode;
    node *prevNode;
    int counter =1 ;
    
    
    
    if(position == 1)
    {
        this->delete_first();
        return;
    }

    while(currentNode)
    {
     
        prevNode = currentNode;
        currentNode = currentNode->next;
        if(counter == position) // we found the spot
            break;
        
        counter++;

    }
    
    prevNode->next = currentNode->next;
    delete currentNode;
    
}

int LinkedList::getFirst(){
    if(this->m_head)
        return this->m_head->data;
    return -1;
}

int LinkedList::getLast(){
    if(this->m_tail)
        return this->m_tail->data;
    
    return -1;
}
