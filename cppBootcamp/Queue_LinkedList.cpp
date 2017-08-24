//
//  Queue_LinkedList.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include "Queue_LinkedList.hpp"

void QueueLinkedList::enqueue(int value){
    
    this->m_list->insertFromTheStart(value);
}
int QueueLinkedList::dequeue(){
    int value = this->m_list->getFirst();
    this->m_list->delete_first();
    
    return value;
}
int QueueLinkedList::peak(){
    return this->m_list->getFirst();
}
