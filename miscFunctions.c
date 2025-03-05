#include "headerA4.h"

//file for sorting and reverse functions

//given a queue of tweet nodes, sorts them by ID in ascending order
//converts the queue into an array, sorts the array using Quick Sort,
//Converts the sorted array back into a queue
void sortID (tweet ** head, tweet ** tail){

    //calculates the number of tweets in the queue
    int numberOfTweets = numTweets(*head);
    //initialize a tweet array of the same size as the queue
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(*head)){
        printf("No nodes to sort\n\n");
        return;
    }
    //otherwise: queue is not empty

    //convert queue into an array
    convertQueueIntoArray(*head, tweetArray, numberOfTweets);
    //sort the array by ID in ascending order
    //4th argument--type of sort--1 for ID, 2 for username
    quickSort(tweetArray, 0, numberOfTweets-1, 1);
    //convert the sorted array back into a queue
    convertArrayIntoQueue(head, tail, tweetArray, numberOfTweets);

    //function stub:
    //printf("--sortID--\n");
}


//given a queue of tweet nodes, sorts them by username ASCII value in ascending order
//converts the queue into an array, sorts the array using Quick Sort,
//Converts the sorted array back into a queue
void sortUsername (tweet ** head, tweet ** tail){

    //calculates the number of tweets in the queue
    int numberOfTweets = numTweets(*head);
    //initialize a tweet array of the same size as the queue
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(*head)){
        printf("No nodes to sort\n\n");
        return;
    }
    //otherwise: queue is not empty

    //convert queue into an array
    convertQueueIntoArray(*head, tweetArray, numberOfTweets);
    //sort the array by username ASCII value in ascending order
    //4th argument--type of sort--1 for ID, 2 for username
    quickSort(tweetArray, 0, numberOfTweets-1, 2);
    //convert the sorted array back into a queue
    convertArrayIntoQueue(head, tail, tweetArray, numberOfTweets);


    //function stub:
    //printf("--sortUsername--\n");
}


//given the queue it reverses the order of the nodes
//converts the queue into an array, reverses the nodes in the array,
//Converts the reversed array back into a queue
void reverse (tweet ** head, tweet ** tail){

    //calculates the number of tweets in the queue
    int numberOfTweets = numTweets(*head);
    //initialize a tweet array of the same size as the queue
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(*head)){
        printf("No nodes to sort\n\n");
        return;
    }
    //otherwise: queue is not empty

    //convert queue into an array
    convertQueueIntoArray(*head, tweetArray, numberOfTweets);
    
    //reverse the array:
    //new array that will hold the reversed queue
    tweet reversedArray[numberOfTweets];

    for(int i = 0; i<numberOfTweets; i++){
        //numberOfTweets-i-1 starts at the last node, i starts at the first node
        reversedArray[numberOfTweets-i-1] = tweetArray[i];
    }

    //convert the reversed array back into a queue
    convertArrayIntoQueue(head, tail, reversedArray, numberOfTweets);

    //function stub:
    //printf("--reverse--\n");
}