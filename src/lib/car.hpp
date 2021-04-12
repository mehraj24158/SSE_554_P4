#pragma once
#include "tire.hpp"
#include "frame.hpp"
#include "engine.hpp"
#include <vector>

class Car
{   
public:
    //attributes
    vector<Tire> tire;
    Frame frame;
    Engine engine;

    int id;
    int price; 

    //constructors
    Car();

};

struct greater_than_car_price
{
    bool operator()(Car& a, Car& b);
}; 