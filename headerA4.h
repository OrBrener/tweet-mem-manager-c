#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> //used for rand()
#include <ctype.h> // used for tolower()
#include <strings.h>


typedef struct microtweet{
    int id; 				//unique integer value	
    char user[51]; 			// the userid / username of the person who wrote the tweet
    char text[141]; 		// the text of the tweet
   
    struct microtweet *next;  //dynamic connection to the next tweet
}tweet;


// function that gets user input
// dynamically alloctes space for each charcter typed.
// keep taking input until a newline character is entered
// returns the whole string as a char pointer
char* getUserInput();

//boolean funciton that checks if a tweet ID is the same as any of the id's in the rest of the list
//return 1 if there is a duplicate, returns 0 if there is no duplicate.
int isSameId(tweet *tweetList, int tweetId);

//function that returns the numeber of nodes (tweets) in the linked list
int numTweets(tweet *tweetList);

//This function will take in a filename as a string pointer and attempt to 
//create a FILE pointer out of it. If the file opens successfully, 
//a FILE pointer will be returned. Otherwise, NULL. 
//TAKEN FROM MY OTHER ASSINGMENTS 
FILE *openFile(char *fileName, char *mode);

//function that given a line from a file, 
//creates a new tweet node and copies the info into the new tweet and returns it
//format in file: id,username,tweet,
//using strtok to seperate the three strings
tweet* getTweetInfo(char* line);

// menu functions 
tweet * createTweet( tweet * tweetList);

void displayTweets(tweet * tweetList);

int searchTweetsByKeyword(tweet * tweetList);

void countStopWords(tweet * tweetList);

void deleteTweet(tweet ** tweetList);

void saveTweetsToFile(tweet * tweetList);

void loadTweetsFromFile(tweet ** tweetList);

// linked list function - required after you create a tweet or load tweets from a file
void addNodeToList(tweet**tweetList,tweet * node);


