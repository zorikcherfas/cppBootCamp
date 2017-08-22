//
//  Queue_LinkedList.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Queue_LinkedList_hpp
#define Queue_LinkedList_hpp

#include <stdio.h>
#include "LinkedList.hpp"
class QueueLinkedList{
    
public:
    
    QueueLinkedList()
    {
        m_list = new LinkedList();
    }
    ~QueueLinkedList()
    {
        
    }
    void enqueue(int value); // add item to queue
    int dequeue(); // remove item from queue
    
    int peak();
    bool isFull();
    bool isEmpty();
    
private:
    LinkedList *m_list;
};
#endif /* Queue_LinkedList_hpp */
