//
//  main.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue_Array.hpp"
#include "Queue_LinkedList.hpp"

using namespace std;

void testing_linkedList();
void testing_stack();
void testing_queue();

int main(int argc, const char * argv[]) {

//    testing_linkedList();
//    testing_stack();
    testing_queue();
    return 0;
}

void testing_linkedList()
{
    
    LinkedList l;
    l.createNode(1);
    l.createNode(2);
    l.createNode(3);
    l.createNode(4);
    
    l.insertFromTheStart(10);
    l.insertFromTheEnd(11);
    l.createNode(12);
    l.display();
    
    l.delete_position(3);
    //    l.insert_position(77, 3);
    
    l.display();
    //    l.delete_last();
    //    l.display();
    //    l.delete_first();
    //    l.display();
}
void testing_stack()
{
    Stack stack(30);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    cout << "Peak: " << stack.peak() <<"\n";
    cout << "Pop: " << stack.pop() <<"\n";
    cout << "Pop: " << stack.pop() <<"\n";

    stack.display();
}

void testing_queue()
{
    Queue_Array qArray(4);
    QueueLinkedList qList;

    cout << "--Queue Array--" <<endl;
    qArray.enqueue(1);
    qArray.enqueue(2);
    qArray.enqueue(3);
    qArray.enqueue(4);
    qArray.enqueue(5);
    qArray.enqueue(6);


    qArray.dequeue();
    qArray.dequeue();
    cout << "Peak: " << qArray.peak() <<"\n";
    
    cout << "--Queue List--" <<endl;

    qList.enqueue(1);
    qList.enqueue(2);
    qList.enqueue(3);
    qList.enqueue(4);
    qList.dequeue();
    cout << "Peak: " << qList.peak() <<"\n";

    

}
