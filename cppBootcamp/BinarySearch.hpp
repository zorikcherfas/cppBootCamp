//
//  BinarySearch.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include <stdio.h>
#include "iostream"
using namespace std;
class BinarySerach{
    
public:
    BinarySerach(int *array , int array_size , int number_to_search){
        m_array = array;
        m_size = array_size;
        m_searchNum = number_to_search;
        
    }
    // 1 , 3, 4, 6, 9 , 11
    bool search()
    {
        int low = 0;
        int high = m_size-1;
        
        bool found = false;
        
        while( (low <= high) && !found)
        {
            int mid = (low + high)/2;
            printf("low = %d\n",low);
            printf("high = %d\n",high);
            printf("mid = %d\n",mid);

            if(m_array[mid] == m_searchNum)
                found = true;
            
            if(m_array[mid] < m_searchNum)
                low = mid+1;
            else{
                high = mid-1;
            }
                
                
            
        }
        
        if(found)
            printf("Entry was found\n");
        else
            printf("Entry wasnot found\n");
        return found;
    }
    

    void printArray(){
        for(int i = 0 ; i < m_size ; i++)
            cout <<m_array[i] <<"\t";
        cout <<endl;
    }
    
private:
    int *m_array;
    int m_size;
    int m_searchNum;
};


#endif /* BinarySearch_hpp */
