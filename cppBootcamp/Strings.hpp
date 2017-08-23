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
};
#endif /* Strings_hpp */
