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
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


using namespace std;
class OS
{
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
        
        pid_t pid;
        
        pid = fork();
        
        if(pid == 0)
        {
            //child prcoress
            printf("This is the child pid %d\n",getpid());
        }
        else
        {
            printf("This is the Father pid %d\n",getpid());
        }
    }
    
    void test2()
    {
        
        pid_t pid;
        
        pid = fork();
        
        if(pid == 0)
        {
            //child prcoress
            printf("This is the child pid - %d  done the progrem: will be zombie(defunct) since father is still working\n",getpid());
        }
        else
        {
            printf("This is the Father pid %d\n",getpid());
            while(1);
        }
    }
    
    
    void  test3()
    {
        
        pid_t pid;
        
        pid = fork();
        
        if(pid == 0)
        {
            //child prcoress
            printf("This is the child pid - %d\n - still in progrem :will be Orphan since Father is done (Father will be init)",getpid());
            while(1);
            
        }
        else
        {
            printf("This is the Father pid %d\n",getpid());
        }
    }
    
    void  test4()
    {
        pid_t child_pid = fork();
        
        // Parent process
        if (child_pid > 0)
            sleep(50);
        
        // Child process
        else
            exit(0); // Will be Zombie
    }
    
    void  test5_wait()
    {
        printf("Different ways in which creation of Zombie can be prevented\n");
        printf("Using Wait and Ingore Signal\n");
        
        int i;
        if( fork() == 0 )
        {
            //Son
            for(i=0 ; i < 20 ; i++)
            {
                printf("I am Child %d\n", getpid());
            }
            
        }
        else
        { // Father
            printf("Using Wait\n");
            int pidToWait = wait(NULL);
            printf("I'm a Father who waiteid son %d\n", pidToWait);
        }
    }
    
    void test5_signal_ignore()
    {
        printf("Different ways in which creation of Zombie can be prevented\n");
        printf("Using Wait and Ingore Signal\n");
        
        int i;
        if( fork() == 0 )
        {
            //Son
            for(i=0 ; i < 20 ; i++)
            {
                printf("I am Child %d\n", getpid());
            }
            
        }
        else
        { // Father
            
            printf("Ignoring Signal\n");
            signal(SIGCHLD, SIG_IGN);
            printf("I'm a perent\n");
            
        }
    }
    
    void signal_hanlder(int signo)
    {
        int pid = wait(NULL);
        printf("Father %d recevice signal from child %d\n", getpid() , pid);
        exit(1);
    }
    
    void test5_signal_hanlder()
    {
        void signal_hanlder();

        printf("Different ways in which creation of Zombie can be prevented\n");
        printf("Using Wait and Ingore Signal\n");
        
        int i;
        if( fork() == 0 )
        {
            //Son
            for(i=0 ; i < 20 ; i++)
            {
                printf("I am Child %d\n", getpid());
            }
            
        }
        else
        { // Father
            
//            signal(SIGCHLD,signal_hanlder);
            printf("I'm a perent\n");
            while(1);
            
        }
    }
};

    
#endif /* OS_hpp */
