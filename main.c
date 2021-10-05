#include "headers.h"
  // CS2211a 2020
  // assignment 5
  // Joshua Ming
  // 251076262
  // jming4
  // November 28, 2020
int main(){
    char input[1000]; // the maximum input can be a string of 1000 characters
    int amountSs = 0; // to count the amount of sentences
    LIST *userInputs = createList(); // make the list
    getStrings(input, userInputs, &amountSs); // get the strings that the user inputs
    printLinkedList(userInputs); // print what the user inputted
    searchWords(userInputs, input); // search for a word that the user inputs
    removeLine(userInputs); // remove a line that the user wishes to remove
    releaseLinks(userInputs); // free the memory occupied by the list
}
