#include "headerA4.h"


//file for all helper functions

//user enters tweet info through stdin
//username and tweet itself need to adhere to certain length restrictions
//userId is created by algorithaem (more comments below)
//returns the newTweet so that it can be passes into addNodeToList()
tweet * createTweet( tweet * tweetList){
    
    //printf("\n");

    //allocate memory for the new tweet being created
    tweet *createdTweet = malloc(sizeof(tweet));


    //Username:
    printf("Enter a username: ");
    char *userName = getUserInput(); //dynamic allocation of characters through user input in stdin

    //making sure that username is between 1-51 characters
    while (strlen(userName) < 1 || strlen(userName) > 51){
        printf("Username has to be between 1 and 51 characters.\n");
        printf("Enter a username: ");
        userName = getUserInput();
    }
    //assign the new tweet "user" with userName
    strcpy(createdTweet->user, userName);
    //deallocate the memory needed by userName
    free(userName);


    //Tweet:
    printf("Enter the user's tweet: ");
    char *userTweet = getUserInput(); //dynamic allocation of characters through user input in stdin
    
    //making sure that tweet is between 1-141 characters
    while (strlen(userTweet) < 1 || strlen(userTweet) > 141){
        printf("tweet has to be between 1 and 141 characters.\n");
        printf("Enter the user's tweet: ");
        userTweet = getUserInput();
    }
    //assign the new tweet "text" with userText
    strcpy(createdTweet->text, userTweet);
    //deallocate the memory needed by userTweet
    free(userTweet);


    //userID:
    //userid = (sum of ascii values of characters in the username) + (length of the user’s tweet).

    //initilize the IDs as 0
    createdTweet->id = 0;
    int userId = 0;

    //sum of ascii values of characters in the username
    for (int i = 0; i<strlen(createdTweet->user); i++){
        userId += createdTweet->user[i];
    }
    //add the length of the user’s tweet
    userId += strlen(createdTweet->text);

    //used by rand()
    srand((int) time(0));

    //checks if there is a duplicate Id in the list as the one calculated above
    int duplicateId = isSameId(tweetList, userId);

    //if there is a duplicate:
    if (duplicateId){
        //loops until there is no longer a duplicate:
        do{
            //adds a random number between 1-999
            userId += (rand() % 999) + 1;
            //checks once again if there is still a duplicate
            duplicateId = isSameId(tweetList, userId);
        }while(duplicateId);
    }

    //ID is calcualted and verified that it is not a duplicate
    createdTweet->id = userId;

    //new tweet is appended to end of the list so it points to NULL
    createdTweet->next = NULL;


    //printf("\n");

    //function stub:
    //printf("--createTweet--\n");

    //return the new tweet so that it can be added to the list using addNodeToList()
    return createdTweet;
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

////given the head of the Queue, frees all the nodes in the list
void freeQueue(tweet **head){
    while (*head != NULL){
        tweet* temp = *head;
        *head = temp->next;
        free(temp);
    }
    *head = NULL;
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

//Given a queue it converts into an array to be used for sorting
void convertQueueIntoArray(tweet *head, tweet* array, int numberOfTweets){
    tweet *temp = head;

    for (int i = 0; i<numberOfTweets; i++){
        array[i] = *temp;
        temp = temp->next;
    }
}

//Given the sorted arrray it converts it back into the queue
void convertArrayIntoQueue(tweet **head, tweet **tail, tweet* array, int numberOfTweets){
    tweet *temp = *head;

    for (int i = 0; i<numberOfTweets; i++){
        temp->id = array[i].id;
        strcpy(temp->user, array[i].user);
        strcpy(temp->text, array[i].text);
        temp->next = temp->next;
        temp = temp->next;
    }
}

// ---- Quicksort Functions ------ //

void swap (tweet * a, tweet * b) {
    
    tweet temp = *a;
    *a = *b;
    *b = temp;
}

int partition (tweet *arr, int low, int high, int type) {
    
    int pivot, pIndex, i;
    if (type == 1){
        pivot = arr[high].id;

        pIndex = low;
    
        for (i = low; i < high; i++) {
            
            if (arr[i].id <= pivot) {
                swap (&arr[i], &arr[pIndex]);
                pIndex++;
            }
        }
    }
    else if (type == 2){
        //pivot = (int)arr[high].user;
        pivot = getASCII(arr[high].user);
        pIndex = low;
    
        for (i = low; i < high; i++) {
            int arrASCIIvalue = getASCII(arr[i].user);
            //if ((int)arr[i].user <= pivot) {
            if (arrASCIIvalue <= pivot){
                swap (&arr[i], &arr[pIndex]);
                pIndex++;
            }
        }
    }
    
    swap (&arr[pIndex], &arr[high]);
    return pIndex;
    
}


void quickSort ( tweet *arr, int low, int high, int type) {

 //  printf ( "quicksort ( %d, %d )\n", low, high );

    if (low < high) {
       
        int pivotIndex = partition (arr, low, high, type);
      /* 
       *  Recursion: perform quickSort for the two sub-arrays, 
       *  one to the left of pivot and one to the right of the pivot 
       */
      quickSort(arr, low, pivotIndex-1, type);
      quickSort(arr, pivotIndex+1, high, type);
   }

}

// ---- Quicksort Functions ------ //

int getASCII(char* username){
    int ASCII = 0;

    for(int i = 0; i<strlen(username); i++){
        ASCII += username[i];
    }

    return ASCII;
}