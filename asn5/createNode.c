#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
sNode *createSentenceNode(LIST * List, int amountSents){
    sNode *newSentence;
    newSentence = (sNode *)calloc(1, sizeof(sNode)); // initialize space for the attributes of the sentence structure
    newSentence->firstWord = NULL; // Since there is no word (yet) initialize to null
    newSentence->lineNum = amountSents; // amountSents corresponds to the line number
    newSentence->numWords = 0; // No words yet
    newSentence->nextSent = NULL; // just a lone sentence for now
    return newSentence;
}

wNode *createWordNode(int strLength){
    wNode *newWord;
    newWord = (wNode*) calloc(1, sizeof(wNode)); // initialize space for the attributes of the word structure
    newWord->cOfW = (char *) calloc(strLength, sizeof(char)); // initialize enough space for the string this word refers to
    newWord->nextWord = NULL; // a lone word for now
    newWord->numChars = 0; // no characters yet
    newWord->wordPos = 0; // to be changed later
    return newWord;
}
