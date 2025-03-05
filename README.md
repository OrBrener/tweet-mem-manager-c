# How to compile and run:
## If using make:
`$make`

`$./A4`

## If not using make:
`$gcc -Wall -std=c99 testA4.c queueFunctions.c miscFunctions.c helper.c -o A4`

`$./A4`


# Explanation of each component:

* ## testA4.c:
    * Harness to test each function for this assignment 
    * Each function is separated into its own block and starts off with an empty queue

* ## helper.c:
    * ### createTweet:
        * user enters tweet info through stdin
        * username and tweet itself need to adhere to certain length restrictions
        * userId is created by algorithm (more comments below)
        * returns the newTweet so that it can be passes into addNodeToList()

    * ### getUserInput:
        * function that gets user input
        * dynamically allocates space for each character typed.
        * keep taking input until a newline character is entered
        * returns the whole string as a char pointer

    * ### isSameId:
        * boolean function that checks if a tweet ID is the same as any of the id's in the rest of the list
        * return 1 if there is a duplicate, returns 0 if there is no duplicate.

    * ### numTweets:
        * function that returns the number of nodes (tweets) in the linked list

    * ### freeQueue:
        * Given the head of the Queue, frees all the nodes in the queue


    * ### convertQueueIntoArray:
        * Given a queue, it converts it into an array
        * used for sorting and reversing 

    * ### convertArrayIntoQueue:
        * Given the sorted or reversed array it converts it back into the queue

    * ### Quicksort Functions:
        * swap
        * partition
        * quickSort

* ## queueFunctions.c:
    * ### enqueue:
        * adds a node to the rear of the queue
        * makes sure to keep the head the same and change the tail to the new node

    * ### dequeue:
        * deletes a mode from the front of the queue
        * makes sure to keep the tail the same and change the head to the next node from the past head
        * returns deleted node
        
    * ### isEmpty:
        * returns 0 if the queue is empty, 1 if it is not empty

    * ### printQueue:
        * prints the whole queue

* ## miscFunctions.c:
    * ### sortID:
        * given a queue of tweet nodes, sorts them by ID in ascending order
        * converts the queue into an array, sorts the array using Quick Sort,
        * Converts the sorted array back into a queue

    * ### sortUsername:
        * given a queue of tweet nodes, sorts them by username ASCII value in ascending order
        * converts the queue into an array, sorts the array using Quick Sort,
        * Converts the sorted array back into a queue
        
    * ### reverse:
        * given the queue it reverses the order of the nodes
        * converts the queue into an array, reverses the nodes in the array,
        * Converts the reversed array back into a queue

# Known Limitations Of The Program:

## Make More Efficient: 
* determining if a userId is unique
    * Instead of relisting each node's ID in the list every time there is a duplicate, 
    * a more efficient manner would be to store each Id as it is created in an array and just append to it. 

## Edge Cases Not Working:
* main: 
    * if a user enter more than one character (non digit) for the input for which function to test, it will print out that it is the wrong input in a loop for the length of the string
    * Similar behavior in the case that the user inputs a non-digit when prompted to indicate how many nodes to add to the queue 


# Future Improvements:

* Implement the efficiency notes outlined above.
* testA4.c
    * Turn each test into a function so that testA4.c has cleaner code and is more concise 
    * Eliminate the need for the user to check if the test case is correct
        * When testing the sort functions implement a isSorted function that checks if it was sorted rather than having the user input if the output is as expected
        * Similarly, have a function that tests the printQueue and reverse functions
    * Implement a function that when the user exits the program it outputs a complete functionally summary with all the tests passed and failed.
* reverse
    * wanted to implement it using 2 stacks but could not get it to work. 
    * kept resulting in infinite loops where in one of the stacks, the last node points to the top
    * Here is the code for my reference:

    * ```C
        //in miscFunctions.c 
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
            printf("converting queue to stack\n");
            for (int i = 0; i<numberOfTweets; i++){
                //printf("dequeuing\n");
                deletedNode = dequeue(head, tail);
                //printf("pushing\n");
                push(deletedNode, &s1);
            }
            //printf("Stack 1\n");
            //printQueue(s1);

            //put the stack into another stack (reversing the order)
            printf("putting stack1 into stack2 (reversing)\n");
            for (int i = 0; i<numberOfTweets; i++){
                //printf("dequeuing\n");
                deletedNode = pop(&s1);
                //printf("pushing\n");
                push(deletedNode, &s2);
            }
            printf("Stack 1\n");
            printQueue(s1);
            printf("Stack 2\n");
            printQueue(s2);

            //convert the reversed stack into the queue
            printf("converting reversed stack into queue\n");
            for (int i = 0; i<numberOfTweets; i++){
                printf("dequeuing\n");
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
   
    * ``` C
        // In helper.c
        void push (tweet* node, tweet** top) {
            
            
            if (*top == NULL) {          // same as !isEmpty (*top)
                *top = node;
            }
            else {
                node -> next = *top;
                *top = node;
            }
            
        }

        tweet* pop (tweet** top) {
            
            tweet* node;
            
            if (!isEmpty (*top)) {         // same as *top == NULL
                node = *top;
                *top = (*top)->next;
                node->next = NULL;
                //printf("node: %d, %s, %s\n", node->id, node->user, node->text);
                
                return node;
            }
            else {
                return NULL;
            }
        }
    