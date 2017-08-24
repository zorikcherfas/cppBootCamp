//
//  FileHanlder.hpp
//  cppBootCamp
//
//  Created by Zorik Cherfas on 24/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef FileHanlder_hpp
#define FileHanlder_hpp

#include <stdio.h>
#include <iostream>
#include "unistd.h"
#include <vector>
#include <string>
#include "iostream"

using namespace std;

class FileHandler{
    
    FILE* m_file;
    char m_path[200];
public:
    
    FileHandler(char *path)
    {
        strcpy(m_path, path);
        
        
        if(access(m_path, F_OK) == -1)
        {
            std::cout << "Error with path %s " <<m_path<<std::endl;
            exit(1);
        }
    }
    ~FileHandler()
    {
        cout <<"FileHandler Class is destroyed" <<endl;
    }
    
    void readFile(){
        m_file = fopen(m_path, "r");

        char buffer[1000] = {0};
        while( !feof(m_file))
        {
            if( fgets(buffer, 1000, m_file)){
                std::cout <<buffer <<std::endl;
            }
        }
        fclose(m_file);
    }
    void readCharacteresFromLine(int numOfLine, int numOfChars)
    {
        m_file = fopen(m_path, "r");
        int currentLine = 0;
        char line[200];
        if(m_file){
            
            while( feof(m_file)!=-1){
                if(fgets(line, 200, m_file)){
                    currentLine++;
                    if(numOfLine == currentLine)
                    {
                        for(int i=0 ; i < numOfChars ; i++)
                            std::cout << line[i];
                        std::cout<<endl;
                        break;
                    }
                    
                }
            }
            
        }
        fclose(m_file);
    }
    void readTail(int numOfLines)
    {
        vector<std::string> list;
        char line[400];
        m_file = fopen(m_path, "r");
    
        while(!feof(m_file)){
            if(fgets(line, sizeof(line),m_file))
                list.push_back(line);
        }
        fclose(m_file);
        
        
        for( int i = list.size() ; i != list.size() - numOfLines; i--)
            cout << list.at(i-1).c_str() <<endl;
        
//        for(vector<std::string>::iterator it = list.begin() + list.size() - numOfLines ; it!= list.end() ; it++)


    }
    void resetFile()
    {
        m_file = fopen(m_path, "w");
        fwrite(NULL, NULL, NULL,m_file);
        fclose(m_file);
    }
    void writeToFileAppend(char *string)
    {
        m_file = fopen(m_path, "a");
        fprintf(m_file,"%s\n", string);
        fclose(m_file);

    }
    void writeFileFromBeginning(char *string)
    {
        vector <std::string> list;
        char buffer[200]= {0};
        m_file = fopen(m_path, "r");
        list.clear();
        
        while(!feof(m_file))
        {
            if(fgets(buffer, 200, m_file))
                list.push_back(buffer);
        }
        fclose(m_file);
        
        m_file = fopen(m_path, "w");

        // testing if all the lines are there
        fprintf(m_file,"%s\n", string);
        
        for(int i = 0 ; i < list.size() ; i++)
            fputs(list[i].c_str(), m_file);


        fclose(m_file);
    }
    
};


#endif /* FileHanlder_hpp */



