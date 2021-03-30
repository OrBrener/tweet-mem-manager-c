#include "headerA4.h"


int main(){
    
    tweet *tweets = NULL;
    tweet *newTweet = NULL;
    int choice = 0;
    int done = 0;
    int isFound;
    
    // do{
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are 'stop words'\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");

        printf("Choose a menu option: ");
        scanf("%d", &choice);
        getchar();

    //     switch(choice){
    //         case 1:
    //             newTweet = createTweet(tweets);
    //             addNodeToList(&tweets, newTweet);
    //             break;
    //         case 2:
    //             displayTweets(tweets);
    //             break;
    //         case 3:
    //             isFound = searchTweetsByKeyword(tweets);
    //             if (isFound == 0){
    //                 printf("There were no matches to the keyword\n\n");
    //             }
    //             break;
    //         case 4:
    //             countStopWords(tweets);
    //             break;
    //         case 5:
    //             deleteTweet(&tweets);
    //             break;
    //         case 6:    
    //             saveTweetsToFile(tweets);
    //             break;
    //         case 7:
    //             loadTweetsFromFile(&tweets);
    //             break;
    //         case 8:
    //             done = 1;

    //             //free all the tweets in the list
    //             while (tweets != NULL){
    //                 tweet * temp = tweets;
    //                 tweets = temp->next;
    //                 free(temp);
    //             }
    //             break;
    //         default:
    //             printf("\nInput has to be between 1-8\n\n");
    //     }
    // }while (done != 1);

    return 0;
}
