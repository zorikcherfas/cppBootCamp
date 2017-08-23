//
//  Network.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 23/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include "iostream"
#include "vector"
class Network{
    
public:
    bool checkIPString(char* ip)
    {
        if(ip==nullptr)
            return false;
        
        int lenght = strlen(ip);
        
//        checking number of octs
        std::vector <int> vec;
        char *p = ip;
        int numOfTokens = 0;
        int n=0;
        int v =0;
        int lastToken = false;
        for(int i = 0 ; i < lenght ; i++)
        {

            if(*(p+i) ==(char)'.' || i==lenght-1)
            {
                numOfTokens++;
                if(n>255)
                {
                    printf("Token is higher than 255\n");
                    return false;
                }
                if(numOfTokens>4)
                {
                    printf("Number of tokens is higher than 255\n");
                    return false;
                }

                vec.push_back(n);
                n =0;
                
                if(numOfTokens == 3)
                    lastToken = true;
            }
            
            else if( *(p+i)<'0' || *(p+i) >'9')
            {
                return false;
            }
//
            if(*(p+i)!='.')
            {
                n = n*10;
                n += *(p+i) - '0';
                v+= n;

            }
        }
      
        printf("Token in Integer format: ");
        for( std::vector<int>::iterator it = vec.begin() ; it!=vec.end(); it++)
            printf("0x%x ", *it);
        std::cout<<std::endl;
        
        return true;
    }
};
#endif /* Network_hpp */
