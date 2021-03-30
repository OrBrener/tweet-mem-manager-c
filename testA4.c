#include "headerA4.h"


int main(){
    
    tweet *tweets = NULL;
    // tweet *newTweet = NULL;
    int choice = 0;
    int done = 0;
    // int queueIsEmpty = 0;
    tweet **head = NULL;
    tweet **tail = NULL;
    tweet *node = NULL;
    tweet *deletedNode = NULL;
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
                printf("Testing [Enqueue] function\nIteration[1]:\n");
                enqueue(head, tail, node);
                break;
            case 2:
                printf("Testing [Dequeue] function\nIteration[1]:\n");
                deletedNode = dequeue(head, tail);
                printf("%d\n", deletedNode->id);
                break;
            // case 3:
            //     headQueue = *head;
            //     printf("Testing [isEmpty] function\nIteration[1]:\n");
            //     queueIsEmpty = isEmpty(headQueue);
            //     break;
            // case 4:
            //     printf("Testing [printQueue] function\nIteration[1]:\n");
            //     printQueue(head);
                break;
            case 5:
                printf("Testing [sortID] function\nIteration[1]:\n");
                sortID(head, tail);
                break;
            case 6:
                printf("Testing [sortUsername] function\nIteration[1]:\n");    
                sortUsername(head, tail);
                break;
            case 7:
                printf("Testing [reverse] function\nIteration[1]:\n");
                reverse(head, tail);
                break;
            case 8:
                printf("\n\nDone Testing!\n\n");
                done = 1;

                //free all the tweets in the list
                while (tweets != NULL){
                    tweet * temp = tweets;
                    tweets = temp->next;
                    free(temp);
                }
                break;
            default:
                printf("\nInput has to be between 1-8\n\n");
        }
    }while (done != 1);

    return 0;
}
