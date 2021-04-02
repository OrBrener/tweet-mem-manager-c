#include "headerA4.h"

void swap (tweet * a, tweet * b) {
    
    tweet temp = *a;
    *a = *b;
    *b = temp;
}

int partition (tweet *arr, int low, int high) {
    
    int pivot, pIndex, i;
    pivot = arr[high].id;
    
    pIndex = low;
    
    for (i = low; i < high; i++) {
        if (arr[i].id <= pivot) {
            swap (&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap (&arr[pIndex], &arr[high]);
    return pIndex;
    
}


void quickSort ( tweet *arr, int low, int high ) {

 //  printf ( "quicksort ( %d, %d )\n", low, high );

    if (low < high) {
       
        int pivotIndex = partition (arr, low, high);
      /* 
       *  Recursion: perform quickSort for the two sub-arrays, 
       *  one to the left of pivot and one to the right of the pivot 
       */
      quickSort(arr, low, pivotIndex-1);
      quickSort(arr, pivotIndex+1, high);
   }

}



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
    quickSort(tweetArray, 0, numberOfTweets-1);

    printf("AFTER SORTIng\n");
    for (int i = 0; i < numberOfTweets; i++){
        printf("%d\n",tweetArray[i].id);
    }

    convertArrayIntoQueue(head, tail, tweetArray, numberOfTweets);
    
    printf("PRTINING QUEUE INSIDE SortID\n");
    printQueue(*head);

    //function stub:
    printf("--sortID--\n");
}

void reverse (tweet ** head, tweet ** tail){

    //function stub:
    printf("--reverse--\n");
}

void sortUsername (tweet ** head, tweet ** tail){

    //function stub:
    printf("--sortUsername--\n");
}