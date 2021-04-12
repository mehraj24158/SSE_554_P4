#pragma once
#include <iostream>  
using namespace std; 

class Frame {
    //attributes
private: 
    int body;
    int nuts_bolts; 
public:

    //constructors
    Frame();
    //methods
    int getBodyStatus(); 
    int countNutsBolts(); 
};