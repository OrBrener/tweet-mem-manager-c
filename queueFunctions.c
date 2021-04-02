#include "headerA4.h"

//adds a node to the rear of the queue
//makes sure to keep the head the same and change the tail to the new node
void enqueue (tweet ** head, tweet ** tail, tweet * node){

    //temp pointer to traverse the list
    tweet *temp = *head;

    //if the list is empty, the first node (head), wull be tweet *node
    if ((*head) == NULL){
        *head = node;
        *tail = node;
    }
    //otherwise: the list is not empty:
    else{
        //loops until the last node
        while (temp->next != NULL){
            temp = temp->next;
        }
        //last node to point to tweet *node 
        temp->next = node;
        *tail = node;
    }
    
    //function stub:
    //printf("--enqueue--\n");
}

//deletes a mode from the front of the queue
//makes sure to keep the tail the same and change the head to the next node from the past head
//returns deleted node
tweet * dequeue (tweet ** head, tweet ** tail){

    tweet *temp = *head;
    tweet *deletedNode = *head;

    // If the queue is empty
    if (isEmpty(temp)){
        printf("No nodes to dequeue\n\n");
        return NULL;
    }
    //If the queue only has one node
    else if(head == tail){
        //make the tail and the head NULL
        //Now there is an empty queue
        *tail = NULL;
        *head = NULL;
        return deletedNode;
    }
    //If there is more than one node
    else {       
	    *head = (*head)->next;
    }

    //function stub:
    //printf("--dequeue--\n");

    //return the dequeued node
    //it will be freed in main
    return deletedNode;
}

//returns 0 if the queue is empty, 1 if it is not empty
int isEmpty (tweet * head){
    
    //function stub:
    //printf("--isEmpty--\n");

    return (head == NULL);
}

//prints the whole queue
void printQueue (tweet * head){
    
    //if empty list (no tweets)
    if (isEmpty(head)){
        printf("No nodes to display\n\n");
        return;
    }

    //temp pointer to traverse the list
    tweet *temp = head;

    //loop through the whole list
    while (temp != NULL){
        printf("%d: Created by %s: %s\n",temp->id, temp->user, temp->text);
        temp = temp->next;
    }

    //function stub:
    //printf("--printQueue--\n");
}
