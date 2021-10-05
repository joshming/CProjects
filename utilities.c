#include "headers.h"
// CS2211a 2020
// assignment 5
// Joshua Ming
// 251076262
// jming4
// November 28, 2020
LIST *createList(){
    LIST *myList;
    if(!(myList = (LIST *)calloc(1, sizeof(LIST)))){ // If there is enough memory for a list to be created, do the following
        myList->firstSentence = NULL;
        myList->numSentences = 0;
    }
    return myList;
}

void addWord(wNode *newWordNode, LIST *myList){
    sNode *currSentence;
    wNode *currWord;
    for(currSentence = myList->firstSentence; currSentence->nextSent != NULL; currSentence = currSentence->nextSent){
    } // empty loop to get to the sentence you want to add the word to
    if(currSentence->firstWord == NULL){
        currSentence->firstWord = newWordNode; // if the sentence has no words, this is the first word
        (currSentence->numWords)++;
    }
    else{
        for(currWord = currSentence->firstWord; currWord->nextWord != NULL; currWord = currWord->nextWord){
        } // to get to the last word in the sentence
        currWord->nextWord = newWordNode; // change the last word to be this new word
        (currSentence->numWords)++;
    }
}

void processLines(char *line, LIST *paraG){
    int i,j, word = 0; // <i> is used to index through the input, <j> is used to index in the new string, <word> is to count the amount of words (for position)
    char newString[1000]; // max string size, this size was initialized earlier
    j = 0;
    for(i=0;i<=(strlen(line));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(line[i]==' '||line[i]=='\0' || line[i] == '\t' || line[i] == '\v')
        {
            if(strlen(newString)>0){
                wNode *newWord;
                newWord = createWordNode(strlen(newString));
                newString[j] = '\0'; // since this is not added when parsing through <line> add this for future purposes
                word++;
                j=0;    // for next word, init index to 0
                strcpy(newWord->cOfW, newString); // copy this string to the space allocated for the string
                newWord->numChars = strlen(newString); // change the number of characters to the number of characters in this word
                newWord->wordPos= word; // update the position which was originally zero
                addWord(newWord, paraG); // add this word to the sentences
                strcpy(newString, ""); // change newString to an empty string to reset it
            }
        }
        else
        {
            if (line[i] != ' ' || line[i] != '\t' || line[i] != '\v'){ // if it is not the end of word
                newString[j] = line[i]; // add this character to the new string
                j++;
            }
        }
    }
}

void addSentences(LIST *lst, sNode *sentence){
    if(lst->firstSentence == NULL){ // if there is no sentences in the list
        lst->firstSentence = sentence; // then make this the first sentence
        (lst->numSentences)++; // increase the number of sentences in the list
    }
    else{
        sNode *currSentence;
        for(currSentence = lst->firstSentence; currSentence->nextSent != NULL; currSentence = currSentence->nextSent){
        } // to get to the end of the list, referring to the last sentence
        currSentence->nextSent = sentence; // make the last sentence point to the new sentence instead of null
        (lst->numSentences)++; // increase the number of sentences
    }
}

void deleteSentence(sNode *sentence){
    wNode *currWord = sentence->firstWord;
    wNode *delWord;
    while(currWord != NULL){ // if currWord is null we have gone too far
        delWord = currWord; // let the <delWord> refer to the same node as currWord
        currWord = currWord->nextWord; // update currWord to point to the next node
        free(delWord->cOfW); // free the data of delWord
        free(delWord); // free delWord
    }
    free(sentence); // once all the words have been freed, free the sentence
}

void changeLineNumbers(LIST *lst){
    int count = 1;
    sNode *currSentence;
    for(currSentence = lst->firstSentence; currSentence != NULL; currSentence = currSentence->nextSent){ // go to each sentence
        if (currSentence->lineNum > count){ // if count, which refers to the proper line number, is less than the line number of the current sentence
            (currSentence->lineNum)--; // then decrement the line number by one
            count++; // go to to the next line
        }
    }
}

void releaseLinks(LIST *myList){
    if(myList->firstSentence == NULL){ // if there are no sentences, then there is nothing to free
        return;
    }
    sNode *delSentence, *currSentence = myList->firstSentence; // else set currSentence to the first sentence
    wNode *delWord, *currWord = currSentence->firstWord; // and set currWord to the first word of the first sentence
    while(currSentence != NULL){ // while we aren't at the end
        while(currWord != NULL){ // while we aren't at the end for the words
            delWord = currWord; // set delWords to the same node as currWord
            currWord = currWord->nextWord; // set currWord to the next word
            free(delWord->cOfW); // free the data of the node
            free(delWord); // free the node
        }
        delSentence = currSentence; // set delSentence to the same node as currSentence
        currSentence = currSentence->nextSent; // set currSentence to the next node
        free(delSentence); // free the sentence
    }

}


