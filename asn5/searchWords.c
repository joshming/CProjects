#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
void searchWords(LIST *myList, char *input){
    while(1){
        printf("Enter a word you would like to find: ");
        gets(input);
        if(input[0] == '\0'){ // if the user enters nothing, then end
            return;
        }
        sNode *currSentence; // to keep track of which sentence we are on
        wNode *currWord; // to keep track of which word we are on
        int found = 0; // to identify if we have found at least one match, 1 is true, 0 is false
        for(currSentence = myList->firstSentence; currSentence != NULL; currSentence =  currSentence->nextSent){ // begin at the first sentence
            for(currWord = currSentence->firstWord; currWord != NULL; currWord = currWord->nextWord){ // begin at the first word of that sentence
                if((strcmp(currWord->cOfW, input)==0)){ // if the current word is the same as what we are looking for
                    found = 1; // we have found a match, therefore, we have found at least one match
                    printf("%s was found in line %d, position %d\n", input, currSentence->lineNum, currWord->wordPos); // display where this word is
                }
            }
        }
        if(found == 0){
            printf("%s was not found in this file\n", input); // if the input is not found in this list, inform the user
        }

    }
}


