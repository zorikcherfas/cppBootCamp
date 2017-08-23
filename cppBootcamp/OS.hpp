//
//  OS.hpp
//  cppBootcamp
//
//  Created by Zorik Cherfas on 22/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef OS_hpp
#define OS_hpp

#include <stdio.h>
#include "iostream"
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
class OS{
private:
    int m_processID;
public:
    OS()
    {
        m_processID = getpid();
    }
    void print()
    {
        cout << "ProcessID " << m_processID << endl;
    }
    
    void test1()
    {
        printf("Test 1 - Zombie process\n");
        
        int i;
        
        int pid = fork();
        
        if(pid == 0 ){
            //Chiled process
            for( i = 0 ; i < 20 ; i++)
            {
                printf("child proceess %d\n", getpid());
            }
        }
        else{
            printf("Father proceess %d\n", getpid());
            while(1);
        }
    }
    
    
    void test2()
    {
        printf("Test 2 - Zombie process\n");
        
        int i;
        
        pid_t child_pid = fork();

        if(child_pid  < 0 )
        {
            printf("Fork Failure\n");
            return ;
        }
        if(child_pid == 0)
        {
                //Chiled process
                printf("child proceess %d\n", getpid());
                exit(0);
    
        }
        else
        {
            printf("Father proceess %d\n", getpid());
            usleep(1000000 * 20); // will sleep for 1 s
            printf("Father done\n");

        }
    }
    
};
#endif /* OS_hpp */
