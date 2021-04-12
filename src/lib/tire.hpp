#pragma once
#include <iostream>
using namespace std; 

class Tire{ 
public: 
    // attributes
    int size; // inches
    string modelName; 
    string completionStatus;

    // constructors
    Tire();
    // Tire(int s= 0, string mod =" ",string comStat=" ");

    // get methods
    int get_size();
    string get_model();
    string returnCompleteStatus(); 

    // set methods
    void set_size(int s);
    void set_model(string mod);
    void setCompleteStatus(string comStat);
};

