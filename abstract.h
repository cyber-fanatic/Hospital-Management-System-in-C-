#pragma once    //compiler directive simpler than include guards 

#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    /*string name;*/
    int age;
    char gender;
public:
    string name;
    Person();
    virtual void input() = 0;          
    virtual void displayInfo() = 0; 
    virtual ~Person() {};
};