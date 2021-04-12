#pragma once
#include <iostream>
using namespace std; 

class Engine{ 
public: 
    // attributes
    int enginesize; 
    string status;  

    // constructors
    Engine();

    // methods
    int engineSize(); 
    string engineStatus(); 
};