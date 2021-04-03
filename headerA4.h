#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> //used for rand()
#include <ctype.h> // used for tolower()
// #include <strings.h>


typedef struct microtweet{
    int id; 				//unique integer value	
    char user[51]; 			// the userid / username of the person who wrote the tweet
    char text[141]; 		// the text of the tweet
   
    struct microtweet *next;  //dynamic connection to the next tweet
}tweet;

struct tweetStack {
    
    int id; 				//unique integer value	
    char user[51]; 			// the userid / username of the person who wrote the tweet
    char text[141]; 		// the text of the tweet
   
    struct tweetStack *next;  //dynamic connection to the next tweet
};

typedef struct tweetStack * Stack;

// ---- Main Funnctionality ------ //

// ---- Queue functions ------ //

//adds a node to the rear of the queue
//makes sure to keep the head the same and change the tail to the new node
void enqueue (tweet ** head, tweet ** tail, tweet * node);

//deletes a mode from the front of the queue
//makes sure to keep the tail the same and change the head to the next node from the past head
//returns deleted node
tweet * dequeue (tweet ** head, tweet ** tail);

//returns 0 if the queue is empty, 1 if it is not empty
int isEmpty (tweet * head);

//prints the whole queue
void printQueue (tweet * head);

// ---- Queue functions ------ //

// ---- Misc functions ------ //

void sortID (tweet ** head, tweet ** tail);

void reverse (tweet ** head, tweet ** tail);

void sortUsername (tweet ** head, tweet ** tail);

// ---- Misc functions ------ //

// ---- main functionality ------ //

// ---- helper functions ------ //

//user enters tweet info through stdin
//username and tweet itself need to adhere to certain length restrictions
//userId is created by algorithaem (more comments below)
//returns the newTweet so that it can be passes into addNodeToList()
tweet * createTweet( tweet * tweetList);

// function that gets user input
// dynamically alloctes space for each charcter typed.
// keep taking input until a newline character is entered
// returns the whole string as a char pointer
char* getUserInput();

//boolean funciton that checks if a tweet ID is the same as any of the id's in the rest of the list
//return 1 if there is a duplicate, returns 0 if there is no duplicate.
int isSameId(tweet *tweetList, int tweetId);

////given the head of the Queue, frees all the nodes in the list
void freeQueue(tweet **head);

//function that returns the numeber of nodes (tweets) in the linked list
int numTweets(tweet *tweetList);

// ---- SortID ------ //

//Given a queue it converts into an array to be used for sorting
void convertQueueIntoArray(tweet *head, tweet* array, int numberOfTweets);

//Given the sorted arrray it converts it back into the queue
void convertArrayIntoQueue(tweet **head, tweet **tail, tweet* array, int numberOfTweets);

//quickSort functions
void swap (tweet * a, tweet * b);
int partition (tweet *arr, int low, int high, int type);
void quickSort ( tweet *arr, int low, int high, int type);
int getASCII(char* username);

// ---- SortID ------ //

tweet* pop (tweet** s);
void push (tweet* node, tweet** s);

// ---- helper functions ------ //
