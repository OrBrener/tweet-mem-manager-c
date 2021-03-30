#include "headerA4.h"


//file for all helper functions

//adds a tweet struct (node) to the end of the list
void addNodeToList(tweet **tweetList, tweet *node){
    
    //temp pointer to traverse the list
    tweet *temp = *tweetList;

    //if the list is empty, the first node (head), wull be tweet *node
    if ((*tweetList) == NULL){
        *tweetList = node;
    }
    //otherwise: the list is not empty:
    else{
        //loops until the last node
        while (temp->next != NULL){
            temp = temp->next;
        }
        //last node to point to tweet *node 
        temp->next = node;
    }

    //function stub:
    //printf("--addNodeToList--\n");

}

// function that gets user input
// dynamically alloctes space for each charcter typed.
// keep taking input until a newline character is entered
// returns the whole string as a char pointer
char* getUserInput(){

    char* text = NULL; // char pointer for all text in user input (stdin)

    int characters = 0; //counter for number of chars read

    do{
        //when the ptr has only been initilized
        if (text==NULL){
            //malloc space 
            text = malloc(sizeof(char));
        }
        //otherwise, text is already intilized:
        else{
            //for every subsequent loop:
            //need to realocate memory for another character of the user input
            text = realloc(text, sizeof(char)*(characters+1));;
        }
        
        
        //get character from user input (stdin)
        fscanf(stdin, "%c", (text + characters));

        characters++;

    //while the user has not entered a newline character
    }while(text[characters-1] != '\n'); 

    //get rid of the tailing newline character at the end of the string 
    text[characters-1] = '\0';
    
    //function stub:
    //printf("--getUserInput--\n"); 
    
    //return the char pointer holding all the text
    return text;
}

//boolean funciton that checks if a tweet ID is the same as any of the id's in the rest of the list
//return 1 if there is a duplicate, returns 0 if there is no duplicate.
int isSameId(tweet *tweetList, int tweetId){
    
    //temp pointer to traverse the list
    tweet *temp = tweetList;

    //loops until the end of the list
    while(temp != NULL){
        //if there is a duplicate ID:
        if (tweetId == temp->id){
            //return true and exit the function
            return 1;
        }
        temp = temp->next;
    }

    //function stub:
    //printf("--isSameId--\n");
    
    //if there is no duplicate, return false.
    return 0;
}

//function that returns the numeber of nodes (tweets) in the linked list
int numTweets(tweet *tweetList){

    int count = 0; //number of nodes in list

    //traverses the whole list
    while (tweetList != NULL){
        count++;
        tweetList = tweetList->next;
    }

    //returns the number of nodes
    return count;
}

//This function will take in a filename as a string pointer and attempt to 
//create a FILE pointer out of it. If the file opens successfully, 
//a FILE pointer will be returned. Otherwise, NULL. 
//TAKEN FROM MY OTHER ASSINGMENTS 
FILE *openFile(char *fileName, char *mode){
    FILE* filePtr = NULL; // File pointer
    
    // Try to open the file 

    #ifdef DEBUG
    printf("Opening file %s.\n\n", fileName);
    #endif
 
    //opens in the reading mode dicated by char *mode 
    filePtr = fopen(fileName, mode); 

    //if no file was found
    if( filePtr == NULL ) { 
        printf("Could not open file %s.\n", fileName);
        return NULL;                                
    }

    //if file was found

    #ifdef DEBUG
    printf("opened %s.\n", fileName);
    #endif

    //function stub:
    //printf("--openFileForReading--\n"); 

    return filePtr;
}

//function that given a line from a file, 
//creates a new tweet node and copies the info into the new tweet and returns it
//format in file: id,username,tweet,
//using strtok to seperate the three strings
tweet* getTweetInfo(char* line){

    //allocate memory for the new tweet being created
    tweet *createdTweet = malloc(sizeof(tweet));
   
    //variabels for the three data points
    int id = 0;
    char* username;
    char* usertweet;

    //counter for the number of commans found
    int loops = 0;

    char delimiter[] = ",";
    
    //ptr will now point to everthing in the line up to the first instance of a ","
    //this is the id
    char *ptr = strtok(line, delimiter);

    //while not the end of the string (line)
    while (ptr != NULL){
        //first comma--ID
        if (loops == 0){
            //convert the ptr into and int and assign it to id
            id = atoi(ptr);
            //get the next ptr (isntance of second ",")
            //points to the username
            ptr = strtok(NULL, delimiter);
            loops++;
        }
        //second comma--username
        else if (loops == 1){
            username = ptr;
            //get the next ptr (instance of the next ",")
            //everthing after the username is the tweet text
            ptr = strtok(NULL, delimiter);
            loops++;
        }
        //for all the rest of the commas--the tweet text
        else {
            usertweet = ptr;
            //get next instance of comma (if there is one)
            ptr = strtok(NULL, delimiter);

            //for the remainder of the string
            while (ptr != NULL){
                //strcat(usertweet, ",");

                //contatinate teh usertweet with the ptr returned above 
                //combines the tweet seperated by commas 
                strcat(usertweet, ptr);

                //get the next instance of a comma (if there is one)
                ptr = strtok(NULL, delimiter);
            }
            //found the id, username, and tweet
            break;
        }
	} //end of retriving data from the line

    //assign createTweet with the data from the line
     createdTweet->id = id;
     strcpy(createdTweet->user, username);
     strcpy(createdTweet->text, usertweet);
     createdTweet->next = NULL; //a new node is appened to the end of the list so it points to NULL

     //printf("ID: %d, Username: %s, Tweet: %s\n", createdTweet->id, createdTweet->user, createdTweet->text);

    //return the creeated Tweet with all the info in it
    return createdTweet;
}
