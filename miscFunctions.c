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

    //if empty list (no tweets)
    if (isEmpty(temp)){
        printf("No nodes to sort\n\n");
        return;
    }
    tweet* s1 = NULL;
    tweet* s2 = NULL;
    printf("Stack 1\n");
    printQueue(s1);
    printf("Stack 2\n");
    printQueue(s2);
    //convert queue into stack
    tweet *deletedNode = NULL; 
    printf("convverting queue to stack\n");
    for (int i = 0; i<numberOfTweets; i++){
        //printf("dequeing\n");
        deletedNode = dequeue(head, tail);
        //printf("pushing\n");
        push(deletedNode, &s1);
    }
    //printf("Stack 1\n");
    //printQueue(s1);

    //put the stack into another stack (reversing the order)
    printf("putting stack1 into stack2 (reversing)\n");
    for (int i = 0; i<numberOfTweets; i++){
        //printf("dequeing\n");
        deletedNode = pop(&s1);
        //printf("pushing\n");
        push(deletedNode, &s2);
    }
    printf("Stack 1\n");
    printQueue(s1);
    printf("Stack 2\n");
    printQueue(s2);

    //convert the revsersed stack into the queue
    printf("convverting reversed stack into queue\n");
    for (int i = 0; i<numberOfTweets; i++){
        printf("dequeing\n");
        deletedNode = pop(&s2);
        printf("pushing\n");
        enqueue(head, tail, deletedNode);
    }
    printf("Stack 1\n");
    printQueue(s1);
    printf("Stack 2\n");
    printQueue(s2);

    printf("Queue\n");
    printQueue(*head);

    //function stub:
    printf("--reverse--\n");
}

void reverse2 (tweet ** head, tweet ** tail){

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

}

int main(){
    //int choice = 0;
    //int done = 0;
    //int queueIsEmpty = 0;
    tweet *head = NULL;
    tweet *tail = NULL;
    tweet *node = NULL;
    //tweet *deletedNode = NULL;
    //tweet *temp = NULL;

    int numTests = 0;
    int testPasses = 0;
    int numNodes = 0;
    int printSuccess = 0;
                numTests = 4;
                testPasses = 0;
                printf("Testing [reverse] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse2(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the reverse function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[2]: Sort Queue with one node\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse2(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the reverse function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[2]: Sort Queue with two nodes\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse2(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the reverse function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
            
                printf("Iteration[4]: Sort Queue with many nodes\n");
                printf("How many nodes would you like to add? ");
                scanf("%d", &numNodes);
                getchar();
                
                for (int i = 0; i<numNodes; i++){
                    node = createTweet(head);
                    enqueue(&head, &tail, node);
                }
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse2(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the reverse function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
                printf("Done Testing [reverse] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                

}