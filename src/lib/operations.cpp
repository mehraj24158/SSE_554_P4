#include "operations.hpp"

std::shared_mutex sm;
std::mutex m1, m2;

//Install Engine if not present in car
void EngineInstaller(Car* c)
{   
    if(&(c->engine) == NULL)
    {
        Engine e;
        c->engine = e;
    }
}

void EngineInstallerVect(std::vector<Car> &cars)
{   
    for(Car c: cars)
    {
        if(&(c.engine) == NULL)
        {
            Engine e;
            c.engine = e;
        }
    }
}

//Install Frame if not present in car
void FrameInstaller(Car* c)
{
    if(&(c->frame) == NULL)
    {
        Frame f;
        c->frame = f;
    }
}

void FrameInstallerVect(std::vector<Car> &cars)
{
    for(Car c: cars)
    {
        if(&(c.frame) == NULL)
        {
            Frame f;
            c.frame = f;
        }
    }
}

//Install Tire if not present in car
void TireInstaller(Car* c)
{
    if(c->tire.size() < 4)
    {
        for(int i = c->tire.size(); i<4; i++)
        {
            Tire t;
            //Tire* x = &t;
            c->tire.push_back(t);
        }
    }
}

void TireInstallerVect(std::vector<Car> &cars)
{
    for(int i = 0; i < cars.size(); i++)
    {
        for(int j = cars[i].tire.size(); j<4; j++)
        {
            Tire t;
            cars[i].tire.push_back(t);
        }
    }
}

//Check if car is are complete
bool Validate(Car& c)
{
    // create shared lock 
    // allows multiple different validation threads to validate a car
    std::shared_lock<std::shared_mutex> sm_lock(sm);

    if(&(c.tire) == NULL || &(c.engine) == NULL || &(c.frame) == NULL)
    {
        return false;
    }
    else
        return true;
}


void dead_lock1()
{   
    // will create deadlock
    std::lock_guard<std::mutex> lock1(m1);
    std::lock_guard<std::mutex> lock2(m2);
}

void dead_lock2()
{
    // will create deadlock
    std::lock_guard<std::mutex> lock1(m2);
    std::lock_guard<std::mutex> lock2(m1);
}

void no_dead_lock()
{
    // locks multiple mutexes without dead_lock
    // std::scoped_lock good_lock(m1, m2);
}