#include "headerA4.h"


int main(){
    
    //tweet *tweets = NULL;
    //tweet *newTweet = NULL;
    int choice = 0;
    int done = 0;
    int queueIsEmpty = 0;
    tweet *head = NULL;
    tweet *tail = NULL;
    tweet *node = NULL;
    tweet *deletedNode = NULL;

    int numTests = 0;
    int testPasses = 0;
    int numNodes = 0;
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

                break;
            case 2:
                printf("Testing [Dequeue] function\nIteration[1]:\n");
                deletedNode = dequeue(&head, &tail);
                printf("%d\n", deletedNode->id);
                break;
            case 3:
                printf("Testing [isEmpty] function\nIteration[1]:\n");
                queueIsEmpty = isEmpty(head);
                if (queueIsEmpty){
                    printf("The Queue is empty\n");
                }
                else{
                    printf("The queue in not empty\n");
                }
                break;
            case 4:
                printf("Testing [printQueue] function\nIteration[1]:\n");
                printQueue(head);
                break;
            case 5:
                printf("Testing [sortID] function\nIteration[1]:\n");
                sortID(&head, &tail);
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

                freeQueue(head);
                break;
            default:
                printf("\nInput has to be between 1-8\n\n");
        }
    }while (done != 1);

    return 0;
}
