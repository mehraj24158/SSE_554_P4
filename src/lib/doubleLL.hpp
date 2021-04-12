#pragma once
#include <iostream>
#include <thread> 
#include "car.hpp"
#include "engine.hpp"
#include "frame.hpp"
#include "tire.hpp"
#include "operations.hpp"
using namespace std; 


//insert node at front of list. 
void push(struct Node** head, int new_data);
//insert new node at given location. 
void append_After(struct Node* prev_node, int new_data);
//inset new node at the end of the list. 
void append_End (struct Node** head, int new_data); 
//displays the double linked list. 
void displayList(struct Node* node);

