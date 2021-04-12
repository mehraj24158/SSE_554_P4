#include "doubleLL.hpp"
using namespace std; 

struct Node{
    Car car; 
    struct Node* next; 
    struct Node* prev; 
};
 
void push(struct Node** head, int new_data)
{ 
    struct Node*  newNode = new Node; 
    newNode -> car.id = new_data; 
    newNode -> next = (*head); 
    newNode -> prev = NULL; 

    if((*head)!= NULL)
    { 
       (*head)-> prev = newNode;
       (*head) = newNode; 
    }
}

void append_After(struct Node* prev_node, int new_data)
{ 
    if(prev_node == NULL)
    { 
        cout<<"No Previous Node"; 
        return; 
    }
    struct Node* newNode = new Node; 
    
    newNode -> car.id = new_data; 
    newNode -> next = prev_node -> next; 
    prev_node -> next = newNode; 
    newNode -> prev = prev_node; 

    if(newNode -> next != NULL)
    { 
        newNode -> next -> prev = newNode; 
    }
}

void append_End (struct Node** head, int new_data)
{
     struct Node* newNode = new Node; 
     struct Node* last = *head; 

     newNode -> car.id = new_data; 

     newNode-> next = NULL; 

    if(*head == NULL){
        newNode -> prev = NULL;
        *head = newNode; 
        return; 
    }

    while(last -> next != NULL)
    {
        last = last->next; 
    }
    last->next = newNode; 
    newNode -> prev = last; 
    return; 
}

void displayList(struct Node* node){ 
    struct Node* last; 
    while( node != NULL){ 
        cout<<node -> car.id<< "--"; 
        last = node; 
        node = node->next; 
    }
    if(node == NULL){
        cout<<"Empty List"; 
    }
}

// int main(){ 
//     struct Node* head = NULL; 
//     return 0; 
// }
