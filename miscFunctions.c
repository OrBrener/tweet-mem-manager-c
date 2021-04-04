#include "headerA4.h"

void sortID (tweet ** head, tweet ** tail){

    tweet *temp = *head;
    int numberOfTweets = numTweets(temp);
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(temp)){
        printf("No nodes to sort\n\n");
        return;
    }

    convertQueueIntoArray(temp, tweetArray, numberOfTweets);
    quickSort(tweetArray, 0, numberOfTweets-1, 1);
    convertArrayIntoQueue(head, tail, tweetArray, numberOfTweets);

    //function stub:
    //printf("--sortID--\n");
}

void sortUsername (tweet ** head, tweet ** tail){

    tweet *temp = *head;
    int numberOfTweets = numTweets(temp);
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(temp)){
        printf("No nodes to sort\n\n");
        return;
    }

    convertQueueIntoArray(temp, tweetArray, numberOfTweets);
    quickSort(tweetArray, 0, numberOfTweets-1, 2);
    convertArrayIntoQueue(head, tail, tweetArray, numberOfTweets);


    //function stub:
    //printf("--sortUsername--\n");
}

void reverse (tweet ** head, tweet ** tail){

    tweet *temp = *head;
    int numberOfTweets = numTweets(temp);
    tweet tweetArray[numberOfTweets];

    //if empty list (no tweets)
    if (isEmpty(temp)){
        printf("No nodes to reverse\n\n");
        return;
    }

    convertQueueIntoArray(temp, tweetArray, numberOfTweets);
    
    tweet reversedArray[numberOfTweets];
    
    for(int i = 0; i<numberOfTweets; i++){
        reversedArray[numberOfTweets-i-1] = tweetArray[i];
    }

    convertArrayIntoQueue(head, tail, reversedArray, numberOfTweets);

    //function stub:
    printf("--reverse--\n");
}