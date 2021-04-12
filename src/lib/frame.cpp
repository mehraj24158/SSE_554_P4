#include "frame.hpp"
using namespace std; 

Frame::Frame() : body(0), nuts_bolts(0){ }

int Frame::getBodyStatus(){ 
    return this->body;
}

int Frame::countNutsBolts(){
    return this->nuts_bolts;
}