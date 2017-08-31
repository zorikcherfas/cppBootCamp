//
//  Questions.hpp
//  cppBootCamp
//
//  Created by Zorik Cherfas on 24/08/2017.
//  Copyright © 2017 Zorik Cherfas. All rights reserved.
//

#ifndef Questions_h
#define Questions_h
using namespace std;
#include <set>
#include<unistd.h>
#include <map>
class Questions{
public:

    void question1(){
        std::cout <<"Battleship game: write a function that finds a ship and return its coordinates\n";
        
        int canvas[5][10];
        memset(canvas , 0 , sizeof(canvas));
        cout <<"size of canavas " <<sizeof(canvas)/sizeof(int)<<endl;
        
        //setting the ship
        canvas[3][2] = 1;
        canvas[3][3] = 1;
        canvas[3][4] = 1;
        
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j = 0 ; j < 10 ; j++)
            {
                if(canvas[i][j] == 0)
                    cout<<"-";
                else
                    cout<<"+";
            }
            cout<<endl;
        }
        
        printf("Searching for the ship\n");
        
        
    }
    
    void question2()
    {
        cout << "Check if two numbers for array at the sum of terget elemnet"<<endl;
        int targetElemnet = 5;
        int array[] = {1,2,3,4,5,7,8};
        bool seen[200] = {false};
        set<int> mySet;
        
        for(int i = 0 ; i < sizeof(array)/sizeof(int) ; i++)
        {
            if(targetElemnet < array[i])
                continue;
      
            int num = targetElemnet - array[i];
            
            if(seen[num] == true)
                cout <<"Sum was found "<<array[i] << ":"<<num<<endl;;
            
            seen[array[i]] = true;
        }
        
    }
    void question3(){
        cout<<"Sort the array in faster than NlogN, when the max interger is known"<<endl;
        
        int array[] = {3,4,1,7,11,6};
        int highestIteger = 11;
        int bucket[highestIteger];
        memset(bucket, 0 ,sizeof(bucket));
        
        for(int i = 0 ; i < sizeof(array)/sizeof(int) ; i++){
            bucket[array[i]]++;
        }
        for(int  i = 0 ; i < highestIteger ; i++){
            if(bucket[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    
    void question4(){
        cout <<"Find the max price you can get from the stock maket\n"<<endl;
        
        int stock[] = {12,11,15,3,10};
        int min_price = stock[0];
        int max_profit = 0;
        
        for(int i = 0 ; i < sizeof(stock)/sizeof(int) ; i++)
        {
            int price = stock[i];
            
            min_price = min(min_price, price);
            int profit = price - min_price;
            max_profit = max(max_profit , profit);
            
        }
        cout <<"Max profit is "<<max_profit <<endl;
    }
    
    void question5(){
        //sort the bipedal dynos..
        FILE* f = fopen("/Users/zorikcherfas/Dev/workspace/cppBootCamp/cppBootcamp/assets/dataset.txt","r");
        
        char line[200] = {};
        std::vector<double> array;
        char *p;
        std::map<std::string, int> myMap;
        std::multimap<string, double> myMutimap;
        double speed;
        
        if(f)
        {
            while(!feof(f)){
                int numOfTokens = 1;
                if(fgets(line, 200 ,f)){
                    char tmp[200] ={};
                    strcpy(tmp, line);
                    p = strtok(tmp, ",");
                    while(p){
                        p = strtok(NULL, ",\n");
                        if(p)
                        {
                            numOfTokens++;
                            if(numOfTokens == 2)
                                speed = atof(p);
                            if(numOfTokens == 3 && (strcmp("herbivore",p) == 0) )
                            {
                                myMutimap.insert(pair<string, double> (p,speed));
                                
                                array.push_back(speed);
                                if(myMap.count(p) == NULL)
                                    myMap[p]= 1;
                                else
                                    myMap[p]+=1;;
                            }
                        }
                    }
                    
                }
            }
            fclose(f);
        }

                
            
//        cout<<"There are "<< array.size()<<" dynto named herbivore in the list" <<std::endl;
        cout<<"There are "<< myMutimap.count("herbivore")<<" dynto named herbivore in the list" <<std::endl;
        
        pair<
            multimap<string, double>::iterator, multimap<string, double>::iterator
            > ppp;
        multimap<string, double> ::iterator it;
        
        ppp = myMutimap.equal_range("herbivore");
        
        for(it = ppp.first ; it!=ppp.second ; it++)
            std::cout<<it->second;
        
        std::sort(array.begin(), array.end());
        for(int i = 0 ; i < array.size() ; i++){
            cout<<array.at(i)<<" ";
        }
        
        cout<<endl;
        
        
    }
    
    void question7()
    {
        //FILE *f = ()
        std::map<string, vector<string>> dec1;
        std::map<string, vector<string>> dec2;
        std::map<string, vector<string>> mergedDec;
        FILE* f1 = fopen("/Users/zorikcherfas/Dev/workspace/cppBootCamp/cppBootcamp/assets/dataset1.txt","r");
        //FILE *f = ()
        FILE* f2 = fopen("/Users/zorikcherfas/Dev/workspace/cppBootCamp/cppBootcamp/assets/dataset2.txt","r");
        
        parseFile(f1, dec1);
        parseFile(f2, dec2);
        
        //merging the files.
        
        std::map<string, vector<string>> ::iterator it;
        vector<string> v;
        it = dec1.begin();
      
        while(it!= dec1.end())
        {
            
            if( dec2.count(it->first))
            {
                for( int i = 0 ; dec1[it->first].size() ; i++)
                    mergedDec[""].push_back(dec1[it->first].at(i));
                for( int i = 0 ; dec2[it->first].size() ; i++)
                    mergedDec[""].push_back(dec2[it->first].at(i));
            }
                
            
        }
        
    }
    
    void parseFile(FILE *f, std::map<string, vector<string>> &dec)
    {
        char line[200];
        string s ;
        
        
        if(f)
        {
            
            while(feof(f) !=-1)
            {
                
                if(fgets(line, 200,f)){
                    string tempLine;
                    tempLine.append(line);
                    
                    char *p = strtok((char *)tempLine.c_str(), ",\n");
                    char *key = p;
                    while(p)
                    {
                        dec[p].push_back(p);
                         p = strtok(NULL, ",\n");
                    }
                }
            }
        }
    }
    /* Function to print permutations of string
     This function takes three parameters:
     1. String
     2. Starting index of the string
     3. Ending index of the string. */
    void permute(char *a, int l, int r)
    {
        int i;
        if (l == r)
            printf("%sn", a);
        else
        {
            for (i = l; i <= r; i++)
            {
                swap((a+l), (a+i));
                permute(a, l+1, r);
           }
        }
    }
    
    /* Function to swap values at two pointers */
    void swap(char *x, char *y)
    {
        char temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
    void question6(){
        
       
        
  
            char str[] = "ABC";
            int n = strlen(str);
            permute(str, 0, n-1);
        
        std::set<string> s;
        std::set<string>::iterator it;
        
        s.insert("zorik");
        
        if(s.count("zorik"))
            cout <<"1 . zorik found" <<endl;
        
//        it = s.find("a");
//        if(it)
//            cout <<"2. a found" <<endl;
        
    }

};
#endif /* Questions_h */
