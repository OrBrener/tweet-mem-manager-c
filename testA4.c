#include "headerA4.h"


int main(){
    
    int choice = 0;
    int done = 0;
    int queueIsEmpty = 0;
    tweet *head = NULL;
    tweet *tail = NULL;
    tweet *node = NULL;
    tweet *deletedNode = NULL;
    tweet *temp = NULL;

    int numTests = 0;
    int testPasses = 0;
    int numNodes = 0;
    int printSuccess = 0;
    printf("Begining the test of Assignment 4!\n");
    
    do{
        printf("1. Test Enqueue Function\n");
        printf("2. Test Dequeue Function\n");
        printf("3. Test isEmpty function\n");
        printf("4. Test printQueue Function\n");
        printf("5. Test sortID Function\n");
        printf("6. Test sortUsername Function\n");
        printf("7. Test reverse Function\n");
        printf("8. Exit\n");

        printf("Choose a menu option: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                numTests = 3;
                testPasses = 0;
                printf("Testing [Enqueue] function\n");

                printf("Iteration[1]: Testing when the queue is empty\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Head and tail should be the same\n");
                printf("Head ID: %d, Tail ID: %d\n", head->id, tail->id);
                if (head == tail){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[2]: Testing when the queue has one node\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Head should be the existing node and tail should be the new node\n");
                printf("Head ID: %d, Tail ID: %d\n", head->id, tail->id);
                if (head != tail && tail == node){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[3]: Testing with a larger queue\n");
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
                printf("Head should be the first node and tail should be the new node\n");
                printf("Head ID: %d, Tail ID: %d\n", head->id, tail->id);
                if (head != tail && tail == node){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Done Testing [Enqueue] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                break;
            case 2:
                numTests = 4;
                testPasses = 0;
                printf("Testing [Dequeue] function\n");

                printf("Iteration[1]: Testing when the queue is empty\n");
                deletedNode = dequeue(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Should not return any node and the queue should still be empty\n");
                if (head == NULL && deletedNode == NULL){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
		        free(deletedNode);

                printf("Iteration[2]: Testing when the queue has many nodes\n");
                do {
                    printf("How many nodes would you like to add? (at least 3) ");
                    scanf("%d", &numNodes);
                    getchar();
                } while(numNodes < 3);
                for (int i = 0; i<numNodes; i++){
                    node = createTweet(head);
                    enqueue(&head, &tail, node);
                }
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");

                printf("Dequeueing\n");
                temp = head;                
                deletedNode = dequeue(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Head should be the second node from the front, returned node should be the old head, and the tail should remain unchanged\n");
                printf("Head ID: %d, Tail ID: %d, deletedNode ID: %d\n", head->id, tail->id, deletedNode->id);
                if (head == temp->next && deletedNode == temp){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
		        free(deletedNode);
            
                printf("Iteration[3]: Testing when the queue has 2 nodes\n");
                printf("Dequeue until only two nodes remain\n");
                for (int i = 0; i<numNodes-3; i++){
                    deletedNode = dequeue(&head, &tail);
                }
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");

                printf("Dequeueing\n");
                temp = head;                
                deletedNode = dequeue(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Head should be the only node left (the same as the tail), returned node should be the old head, and the tail should remain unchanged\n");
                printf("Head ID: %d, Tail ID: %d, deletedNode ID: %d\n", head->id, tail->id, deletedNode->id);
                if (head == temp->next && deletedNode == temp && head == tail){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
		        free(deletedNode);

                printf("Iteration[4]: Testing when the queue has only 1 node\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");

                printf("Dequeueing\n");
                temp = head;                
                deletedNode = dequeue(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Head and tail should be NULL, list should be empty\n");
                if (head == NULL && deletedNode == temp){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
		        free(deletedNode);

                printf("Done Testing [Dequeue] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                break;
            case 3:
                numTests = 4;
                testPasses = 0;
                printf("Testing [isEmpty] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                queueIsEmpty = isEmpty(head);
                if (queueIsEmpty){
                    printf("The Queue is empty\n");
                }
                else{
                    printf("The queue in not empty\n");
                }
                if (queueIsEmpty && head == NULL){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[2]: Queue with one node\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                queueIsEmpty = isEmpty(head);
                if (queueIsEmpty){
                    printf("The Queue is empty\n");
                }
                else{
                    printf("The queue in not empty\n");
                }
                if (!queueIsEmpty && head != NULL){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[3]: Queue with many nodes\n");
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
                queueIsEmpty = isEmpty(head);
                if (queueIsEmpty){
                    printf("The Queue is empty\n");
                }
                else{
                    printf("The queue in not empty\n");
                }
                if (!queueIsEmpty && head != NULL){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[4]: First dequeing the whole queue and then testing\n");
                printf("Dequeueing\n");
                for (int i = 0; i<numNodes+1; i++){
                    deletedNode = dequeue(&head, &tail);
                }
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                queueIsEmpty = isEmpty(head);
                if (queueIsEmpty){
                    printf("The Queue is empty\n");
                }
                else{
                    printf("The queue in not empty\n");
                }
                if (queueIsEmpty && head == NULL){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Done Testing [isEmpty] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                break;
            case 4:
                numTests = 4;
                testPasses = 0;
                printf("Testing [printQueue] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Is the print function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[2]: Queue with one node\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Is the print function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[3]: Queue with many nodes\n");
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
                printf("Is the print function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[4]: First dequeing the whole queue and then testing\n");
                printf("Dequeueing\n");
                for (int i = 0; i<numNodes+1; i++){
                    deletedNode = dequeue(&head, &tail);
                }
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Is the print function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Done Testing [printQueue] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                break;
            case 5:
                numTests = 4;
                testPasses = 0;
                printf("Testing [sortID] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("SORTING THE QUEUE\n");
                sortID(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("Does the sortID function work as expected? (0/1) ");
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
                printf("SORTING THE QUEUE\n");
                sortID(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("Does the sortID function work as expected? (0/1) ");
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
                printf("SORTING THE QUEUE\n");
                sortID(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("Does the sortID function work as expected? (0/1) ");
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
                printf("SORTING THE QUEUE\n");
                sortID(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("does the sortID function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }
                printf("Done Testing [sortID] Function\n");
                if (testPasses == numTests){
                    printf("ALL TESTS PASSED\n\n");
                } else {
                    printf("Only %d out of %d tests passed\n", testPasses, numTests);
                }
                printf("Freeing all nodes\n\n");
                freeQueue(&head);
                break;
            case 6:
                printf("Testing [sortUsername] function\nIteration[1]:\n");    
                sortUsername(&head, &tail);
                break;
            case 7:
                printf("Testing [reverse] function\nIteration[1]:\n");
                reverse(&head, &tail);
                break;
            case 8:
                printf("\n\nDone Testing!\n\n");
                done = 1;

                freeQueue(&head);
                break;
            default:
                printf("\nInput has to be between 1-8\n\n");
        }
    }while (done != 1);

    return 0;
}
