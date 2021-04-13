#include "engine.hpp"
using namespace std; 
Engine::Engine(){}

int engineSize(){
    int esize = 6; //6 represents a 6 cyclinder vehicle (V6)
    return esize; 
}
string engineStatus(string engineStatus)
{ 
    int estatus = 1; 
    if(estatus == 1)
    {
         engineStatus = "Engine passed.";
    }
    else{ 
        engineStatus = "Engine failed.";
    }
    return engineStatus; 
};
