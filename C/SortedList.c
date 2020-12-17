#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    //Any Arbitrary data
    char *name;

} Data;


//Sorted List Node
typedef struct node{
    //The lower the priority the more important the node
    int priority;
    Data* data;
    struct node *ptr;
} node_sort;

//----- LINKED LIST -----
typedef struct LinkedList_s {
    int height;
    node_sort* head;
    node_sort* tail;
} LinkedList_s;


//----- CREATE LINKED LIST -----
LinkedList_s* createSortedList()
{
   LinkedList_s* list = malloc(sizeof(LinkedList_s));
   list->height=0;
   return list;
}

//Creates a node in the stack
node_sort* createStackNode(Data* data, int priority){
    node_sort* temp = malloc(sizeof(node_sort));// Allocate memory slot
    temp->priority = priority;
    temp->data = data;

    return temp;
}

//insert a node into the list
void insert(LinkedList_s* linked, node_sort* l){
    if (linked->head == NULL){//Add the node to an empty list
        linked->head = l;

    }else if ( l->priority <= linked->head->priority){//Add the node to the front 
        l->ptr = linked->head;
        linked->head = l;
    }
    else{

    node_sort *prev = linked->head;// = malloc(sizeof(node_sort));
    node_sort *next = linked->head->ptr;
    int i = 0;

    while(next != NULL && i == 0){//sort the node
       
        if (l->priority <= next->priority){
            i = 1;
        }else{
        prev = next;
        next = next->ptr;}
    }
    
        prev->ptr = l;
        l->ptr = next;
    
    }

    linked->height++;
    

}


node_sort* dequeue(LinkedList_s *list){
    node_sort* temp = list->head;
    list->head = list->head->ptr;

    list->height--;
    return temp;
}

/*
int main(void){
    LinkedList_s* linked_list = createSortedList();

    node_sort* list = createStackNode( createLeaf('c', 5) );
    insert(linked_list, list);

    list = createStackNode( createLeaf('r', 3) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('e', 4) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('g', 3) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('q', 2) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('k', 6) );
    insert(linked_list, list);

    printf("%d\n", linked_list->head->ptr->priority);

}*/
