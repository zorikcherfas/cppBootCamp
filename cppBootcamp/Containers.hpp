//
//  Containers.hpp
//  cppBootCamp
//
//  Created by Zorik Cherfas on 24/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Containers_hpp
#define Containers_hpp

#include <stdio.h>
#include <iostream>
#include "list"
#include "map"
#endif /* Containers_hpp */
using namespace std;
class Containers{

public:
  
    void testLinkedList()
    {
        std::list<std::string> myList;
        myList.push_back("a");
        myList.push_back("c");
        myList.push_back("b");
        myList.push_back("aa");
        myList.push_front("1");
        
        list<string>::iterator it;
        
        it = myList.begin();
        it++;
        myList.insert(it, "new");
        myList.sort();
        myList.reverse();
        while(myList.size())
        {
            std::cout<<myList.front()<<",";
            myList.pop_front();
        }
        
    }
    
    void testMap()
    {
    }
};
