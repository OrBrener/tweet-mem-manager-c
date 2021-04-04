# Student Info + Academic Integrity:

## Student Name: Or Brener
### Student ID: 1140102
## Assignment 4
## Course: CIS*2500
### Date of last revision: April 3rd 2021
### Due Date: April 7th, 2021

## Academic Integrity
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1. I have read and understood the policy on academic integrity.
2. I have completed Moodle's module on academic integrity.
3. I have achieved at least 80% on the academic integrity quiz I assert that this work is my own. I have appropriate acknowledged any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.


# How to compile and run:
## If using make:
`$make`

`$./A4`

## If not using make:
`$gcc -Wall -std=c99 testA4.c queueFunctions.c miscFunctions.c helper.c -o A4`

`$./A4`


# Explanation of each component:

* ## testA4.c:
    * Harness to test each function for this assingnment 
    * Each function is sperated into its own block and starts off with an empty qeueue

* ## helper.c:
    * ### createTweet:
        * user enters tweet info through stdin
        * username and tweet itself need to adhere to certain length restrictions
        * userId is created by algorithm (more comments below)
        * returns the newTweet so that it can be passes into addNodeToList()
        * TAKEN FROM ASSIGNMENT 3

    * ### getUserInput:
        * function that gets user input
        * dynamically allocates space for each character typed.
        * keep taking input until a newline character is entered
        * returns the whole string as a char pointer
        * TAKEN FROM ASSINGMENT 3

    * ### isSameId:
        * boolean function that checks if a tweet ID is the same as any of the id's in the rest of the list
        * return 1 if there is a duplicate, returns 0 if there is no duplicate.
        * TAKEN FROM ASSINGMENT 3

    * ### numTweets:
        * function that returns the number of nodes (tweets) in the linked list
        * TAKEN FROM ASSINGMENT 3

    * ### freeQueue:
        * Given the head of the Queue, frees all the nodes in the queue


    * ### convertQueueIntoArray:
        * Given a queue, it converts it into an array
        * used for sorting and reversing 

    * ### convertArrayIntoQueue:
        * Given the sorted or reversed arrray it converts it back into the queue

    * ### Quicksort Functions:
        * TAKEN FROM THE EXMAMPLE IN CLASS "stack_LL_2.c"
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

    * ### printQeueue:
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
    * Similar behaviour in the case that the user inputs a non-digit when prompted to indicate how many nodes to add to the qeueue 


# Future Improvements:

* Implement the efficiency notes outlined above.
* testA4.c
    * Turn each test into a function so that testA4.c has cleaner code and is more conciece
    * Eliminate the need for the user to check if the test case is correct
        * When testing the sort functions impliment a isSorted function that checks if it was sorted rather than having the user input if the output is as expected
        * Similarly, have a function that tests the printQueue and reverse functions
    * Implement a function that when the user exits the program it outputs a complete functionally summary with all the tests passsed and failed.
* reverse
    * wanted to impliment it using 2 stacks but could not get it to work. 
    * kept resuling in infinte loops where in one of the stacks, the last node points to the top
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
    
# END OF README