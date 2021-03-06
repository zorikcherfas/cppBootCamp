//
//  main.cpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#include <iostream>
#include "unitest.hpp"
using namespace std;


int main(int argc, const char * argv[]) {

//    testing_linkedList();
//    testing_stack();
//    testing_queue();
//    testing_BinarySearch();
//    testing_os();
//    testing_network();
//    testing_strings();
//    testing_file();
//    testing_containres();
    testing_quesionts();
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

void testing_BinarySearch(){
    int array[] = {1,3,5,6,9,11};
    int arraySize = sizeof(array) / sizeof(int);
    
    BinarySerach *binarySearch = new BinarySerach(array, arraySize , 5);
    
    binarySearch->printArray();
    binarySearch->search();

}

void testing_os()
{
    OS os;
//    os.test1();
//    os.test2();
//    os.test6_pipe_between_process();
//    os.test7_runsystem();
    os.test8_runexec();
}
void testing_network(){
    Network network;
    char ip[] = "10.100.221.3";
    network.checkIPString(ip);
    
}
void testing_strings()
{
    Stings s;
    char array[] = "aB";
//    s.test1_possible_combinations(array);
    
    s.parsingFile();
}
void testing_file()
{
    FileHandler *fileHanlder = new FileHandler("/Users/zorikcherfas/Dev/workspace/cppBootCamp/cppBootcamp/assets/zorik.txt");
//    fileHanlder->readFile();
//    fileHanlder->resetFile();
//    fileHanlder->writeToFileAppend("testing1");
//    fileHanlder->writeToFileAppend("testing2");
//    fileHanlder->writeToFileAppend("testing3");
//      fileHanlder->readTail(1);
//    fileHanlder->readFile();
//    fileHanlder->readCharacteresFromLine(2, 20);
}
void testing_containres()
{
    Containers cntr;
    cntr.testLinkedList();
}

void testing_quesionts()
{
    Questions q;
//    q.question1();
//    q.question2();
//    q.question3();
//    q.question4();
//    q.question5();
//    q.question6();
    q.question7();

}
