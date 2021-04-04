#include "headerA4.h"

//Harness to test each function for this assingnment
//Each function is sperated into its own block and starts off with an empty qeueue

int main(){
    
    //variables for choing which function to test
    int choice = 0;
    int done = 0;

    //pointer for the queue
    tweet *head = NULL;
    tweet *tail = NULL;

    //pointer to created node
    tweet *node = NULL;
    //pointer to deleted node
    tweet *deletedNode = NULL;
    //boolean saying if the queue is empty
    int queueIsEmpty = 0;
    //temporary node (multiple uses)
    tweet *temp = NULL;

    //intilize varibales
    int numTests = 0;
    int testPasses = 0;
    int numNodes = 0;
    int printSuccess = 0;

    printf("Begining the test of Assignment 4!\n");
    do{
        //main menu options
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
        //get rid of newline from the input
        getchar();

        switch(choice){
            //Enqueue function
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
            //Dequeue function
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
                    free(deletedNode);
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
            //isEmpty function
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
                    free(deletedNode);
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
            //printQueue function
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
                    free(deletedNode);
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
            //sortID function
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
                printf("\n");
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
                printf("\n");
                printf("Does the sortID function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[3]: Sort Queue with two nodes\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("SORTING THE QUEUE\n");
                sortID(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
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
                printf("\n");
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
            //sortUsername function
            case 6:
                numTests = 4;
                testPasses = 0;
                printf("Testing [sortUsername] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("\n");
                printf("SORTING THE QUEUE\n");
                sortUsername(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the sortUsername function work as expected? (0/1) ");
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
                sortUsername(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the sortUsername function work as expected? (0/1) ");
                scanf("%d", &printSuccess);
                getchar();
                if (printSuccess){
                    printf("SUCCESS!\n\n");
                    testPasses++;
                }

                printf("Iteration[3]: Sort Queue with two nodes\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("SORTING THE QUEUE\n");
                sortUsername(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("Does the sortUsername function work as expected? (0/1) ");
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
                sortUsername(&head, &tail);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("does the sortUSername function work as expected? (0/1) ");
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
            //Reverse function
            case 7:
                numTests = 4;
                testPasses = 0;
                printf("Testing [reverse] function\n");
                printf("Iteration[1]: Empty Queue\n");
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse(&head, &tail);
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

                printf("Iteration[2]: Reverse Queue with one node\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse(&head, &tail);
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

                printf("Iteration[3]: Reverse Queue with two nodes\n");
                node = createTweet(head);
                enqueue(&head, &tail, node);
                printf("\nPRINTING THE QUEUE\n");
                printQueue(head);
                printf("\n");
                printf("REVERSING THE QUEUE\n");
                reverse(&head, &tail);
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
            
                printf("Iteration[4]: Reverse Queue with many nodes\n");
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
                reverse(&head, &tail);
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
                break;
            //Done testing
            case 8:
                printf("\nDone Testing!\n\n");
                done = 1;
                //free the queue
                freeQueue(&head);
                break;
            //not valid input
            default:
                printf("\nInput has to be between 1-8\n\n");
        }
    //loops until user is finished (chooses option 8)
    }while (done != 1);

    return 0;
}
