#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
void removeLine(LIST *myList){
    if (myList->firstSentence == NULL){
        return;
    }
    char input[1000]; // to receive the users input
    int line; // to use if the user inputs a number
    while(1){
        printf("Enter the line number you would like to delete: ");
        gets(input);
        if (input[0] == '\0'){ // if the user inputs nothing, then exit this loop and function
            return;
        }
        else if(!(atoi(input))){ // if the value returned is 0, then it is not a number
            printf("You did not enter an integer, try again.\n"); // inform the user to input a number and not something else
        }
        else if(atoi(input) > myList->numSentences){ // if the number entered is too large for the list, prompt the user to try again
            printf("The Number you entered was too large for this paragraph. Please try again.\n");
        }
        else{ // else look for this line
            line = atoi(input);
            sNode *currSentence, *prevSent;
            for(currSentence = myList->firstSentence, prevSent = NULL; currSentence->lineNum != line; prevSent = currSentence, currSentence = currSentence->nextSent){
            } // to get to the sentence with the desired line number
            if (prevSent == NULL){ // if its the first sentence
                myList->firstSentence = currSentence->nextSent; // then move the first sentence pointer to the next sentence
                (myList->numSentences)--; // decrement the amount of sentences by one
            }
            else{
                prevSent->nextSent = currSentence->nextSent; // make the previous sentence point to the sentence after the one we are deleting
                (myList->numSentences)--; // decrement the amount of sentences by one
            }
            deleteSentence(currSentence); // delete the sentence with the line number
            changeLineNumbers(myList); // update each sentences' line number
            printLinkedList(myList); // print the update list
        }
    }
}
