//
//  Strings.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 23/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Strings_hpp
#define Strings_hpp

#include <stdio.h>
#include "iostream"
#include <algorithm>
#include <cmath>
#include "vector"
#include "set";
#include "map"
using namespace std;
class Stings{
    
public:
    void test1_possible_combinations(char *array)
    {
        
        
        int pownumberOfCombinations = std::pow(strlen(array), 2);
        
        std::string str = array;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::cout << str <<std::endl;
        
        std::bitset<10> bitset1;
//        bitset1.set(2);
//        std::cout<<2<<" "<< bitset1<<std::endl;
        bitset1.reset();
        for(int i = 0 ; i < pownumberOfCombinations ; i++)
        {
            bitset1 =i;
            std::cout<<i<<" "<< bitset1<<std::endl;
//            bitset1.reset(i);
        }
        
        
    }
    void parsingFile()
    {
        char logfile[] = "prcoess id:3 thread:10";
        //getting the process id
        char *p = strtok(logfile, ":");
        std::vector<std::string> array;
        std::map<std::string, int> myMap;
        //option 1
        while(p)
        {
//            std::cout<<p<<std::endl;
            array.push_back(p);
            p = strtok(NULL, ": ");
        }
        for(int i = 0 ; i < array.size(); i++)
        {
            if(i == 1)
                myMap[std::string("processID")] = std::stoi(array.at(i).c_str());
            if(i == 3)
                myMap[std::string("threadID")] = std::stoi(array.at(i).c_str());
        }
        
        std::cout<<"Getting stuff from log"<<std::endl;
        cout<<"ProcessID is "<< myMap["processID"] <<endl;
        cout<<"threadID is "<< myMap["threadID"] <<endl;
        
        multimap<string, int> testmap;
        testmap.insert(pair<string,int> ("zorik",1));
        testmap.insert(pair<string,int> ("zorik",2));
        std::cout << testmap.size() << std::endl;

        //option 2
        
    }
};
#endif /* Strings_hpp */
