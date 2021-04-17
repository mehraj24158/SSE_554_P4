#pragma once
#include <iostream>
#include <thread>
#include "car.hpp"
#include "tire.hpp"
#include "frame.hpp"
#include <mutex>
#include <shared_mutex>



//Install Engine if not present in car
void EngineInstaller(Car* c);
void EngineInstallerVect(std::vector<Car> &cars);

//Install Engine if not present in car
void FrameInstaller(Car* c);
void FrameInstallerVect(std::vector<Car> &cars);

//Install tires if not present in car
void TireInstaller(Car* c);
void TireInstallerVect(std::vector<Car> &cars);

//Check if car is complete
bool Validate(Car& c);

void dead_lock1();

void dead_lock2();

void no_dead_lock();