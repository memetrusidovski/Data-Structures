#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    StackNode* _next; 
}StackNode;

typedef struct Stack{
    int height;
    StackNode* _top;
}Stack;

//----CREATE A STACK----
Stack* createStack(StackNode* head){
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    newStack->height = 1;

    newStack->_top = head;

    return newStack;
}

//----INSERT A NEW VALUE----
void insert(Stack* stack, int data){
    //Create new node and set data
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->_next = stack->_top; 

    //Point old top of the stack to the new one
    stack->height++;
    stack->_top = newNode;
}

//----POP A VALUE FROM THE STACK----
StackNode* pop(Stack stack){
    //Create a temporay node
    StackNode* temp = (StackNode*) malloc(sizeof(StackNode));
    temp = stack._top;
    temp->_next = NULL;

    //Set new top
    stack.height--;
    stack._top = stack._top->_next;

    return temp;
}

int main(void){

}