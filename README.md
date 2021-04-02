# Student Info + Academic Integrity:

## Student Name: Or Brener
### Student ID: 1140102
## Assignemnt 4
## Course: CIS*2500
### Date of last revison: April 1st 2021
### Due Date: April 7tth, 2021

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

## Main:
driver function of the program.
Gets input from the user and runs the neccessary functions

## helper:
### addNodeToList:
* adds a tweet struct (node) to the end of the list

### getUserInput:
* function that gets user input
* dynamically alloctes space for each charcter typed.
* keep taking input until a newline character is entered
* returns the whole string as a char pointer

### isSameId:
* boolean funciton that checks if a tweet ID is the same as any of the id's in the rest of the list
* return 1 if there is a duplicate, returns 0 if there is no duplicate.

### numTweets:
* function that returns the numeber of nodes (tweets) in the linked list

### openFile:
* This function will take in a filename as a string pointer and attempt to 
* create a FILE pointer out of it. If the file opens successfully, 
* a FILE pointer will be returned. Otherwise, NULL. 
* TAKEN FROM MY OTHER ASSINGMENTS 

### getTweetInfo:
* function that given a line from a file, 
* creates a new tweet node and copies the info into the new tweet and returns it
* format in file: id,username,tweet,
* using strtok to seperate the three strings

### createTweet: 
* user enters tweet info through stdin
* username and tweet itself need to adhere to certain length restrictions
* userId is created by algorithaem (more comments below)
* returns the newTweet so that it can be passes into addNodeToList()

## displayTweets:
* All tweets in the current linked list are printed to stdout.
* <id>: Created by <user>: <text>


# Known Limitations Of The Program:

## make more efficent: 
* determining if a userId is unique. Instead of relisting each node's ID in the list every time there is a duiplicate, 
* a more efficent manner would be to store each Id as it is created in an array and just append to it. 

## findStopWords: 
* inefficent way of checking if is a stopword. It can be divided into words that start with {a,b,f,h,i,o,t,w} and search that way.

## Edge Cases Not Working:
### main: 
* if a user enter more than one character (non digit), it will print out that it is the wrong input in a loop for the length of the string


# Future Improvments:

* impliment the efficency notes outlined above.
* Allow the user to search tweets based on username as well as tweet text 