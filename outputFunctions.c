#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
void printLinkedList(LIST *myList){
    if(myList->firstSentence == NULL){
        return;
    }
    sNode *currSentence; // to keep track of which sentence we are on
    wNode *currWord; // to keep track of which word we are on in the sentence
    printf("These are your words printed out:\n");
    for(currSentence = myList->firstSentence; currSentence != NULL; currSentence = currSentence->nextSent){ // continue until we get to the end, aka when currSentence is NULL
        for(currWord = currSentence->firstWord; currWord != NULL; currWord = currWord->nextWord){ // continue until the end, when currWord is NULL
            printf("%s ", currWord->cOfW);
        }
         printf("\n");
    }
    printf("\n");

}

