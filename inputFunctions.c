#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
int getStrings(char *input, LIST *myList, int *amountSents){
    while(1){ // while true, aka infinite
        printf("Please enter a string: ");
        gets(input); // get the input
        if(input[0] == '\0'){ // if the user inputs an empty line, aka presses enter
            return 0; // immediately end
        }
        sNode *newSentence; // set up a new sentence node
        (*amountSents)++; // increase the amount of sentences by one
        newSentence = createSentenceNode(myList, *amountSents); // create the new sentence with the following data
        addSentences(myList, newSentence); // add the sentence to the list
        processLines(input, myList); // make the words of the sentence
    }
    return 0;
}

