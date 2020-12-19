#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    //Any Arbitrary data
    char *name;

} Data;

//Sorted List Node
typedef struct Node{
    //The lower the priority the more important the node
    Data* data;
    struct Node *ptr;
} Node;

//----- LINKED QUEUE -----
typedef struct Queue {
    int height;
    Node* _front;
    Node* _back;
} Queue;

Queue* create(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->height = 0;

    return queue;
}

void push(Queue* queue, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(queue->height == 0){
        queue->_front = newNode;
        queue->_back = newNode;
    }
    else{
        queue->_back->ptr = newNode;
    }

    queue->height++;
}


Node* dequeue(Queue* queue){
    Node* temp = (Node*)malloc(sizeof(Node));

    temp = queue->_front;
    queue->_front = queue->_front->ptr;

    return temp;
}
int main(void){

}