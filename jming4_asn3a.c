/* CS2211a 2020 */
/* Assignment 03 */
/* Joshua Ming */
/* 251076262 */
/* jming4 */
/* October 15, 2020 */ 
#include <stdio.h>

int main(){
    int array[] = {12, 63, 44, 89, 3, 55, 73, 27, 37, 18, 19, 26, 33, 98, 103};
    int count = 0, sizeInBytes = sizeof(array), sizeElements = sizeInBytes/sizeof(int);
    printf("Size of array: %d bytes \n", sizeInBytes);
    printf("Length of array: %d elements \n", sizeElements);

    printf("\nPART 1:\nThe values store into the array are :\n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
        {
            printf(" %d ", array[i]);
        }
        
    }
    printf("\nPART 2: \nThe values store into the aray in reverse are :\n");
    for(int i = sizeElements - 1; i >= 0; i--){
        if(i == 0){
            printf(" %d\n", array[i]);
        }
        else
        {
            printf(" %d ", array[i]);
        }
    }
    printf("\nPART 3: \nThe smallest value stored in the array is :\n");
    int minVal = 0, position;
    for (int i = 0; i < sizeElements; i++){
        if(minVal == 0){
            minVal = array[i];
            position = i;
        }
        else if(array[i] < minVal){
            minVal = array[i];
            position = i;
        }
        else 
            continue;
    }
    printf("value: %d at the %dth position from the left\n", minVal, position + 1);

    printf("\nPART 4:\nThe sum (total) value of the array is :\n");
    int total = 0;
    for (int i = 0; i < sizeElements; i++){
        total += array[i];
        if (i == sizeElements - 1){
            printf("%d ", array[i]);
        }
        else 
            printf("%d + ", array[i]);
    }
    printf("equals: %d\n", total);

    printf("\nPART 5:\n Copy the array into a new array, but in reverse order :\nOrginal array : \n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
    printf("Changed array :\n");
    int arrayRev[sizeElements]; 
    for(int i = sizeElements - 1; i >= 0; i--){
        arrayRev[i + 1 - sizeElements] = array[i];
        if(i == 0){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
    printf("\nPART 6:\nSwitch the first value in the array with the last value in the array :\n");
    printf("Original array :\n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
    int tmp; 
    tmp = array[0];
    array[0] = array[sizeElements -1];
    array[sizeElements -1] = tmp;
    printf("Changed array :\n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
    printf("\nPART 7:\nSort the array in ascending order:\nOriginal array :\n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
    for(int j = 0; j < sizeElements -1; j ++){
        for(int i = 0; i < sizeElements -1; i ++){
            if (array[i] > array[i+1]){
                tmp = array[i+1];
                array[i+1] = array[i];
                array[i] = tmp;
            }
        }
    }
    printf("Changed array :\n");
    for(int i = 0; i < sizeElements; i ++){
        if(i == sizeElements -1){
            printf(" %d\n", array[i]);
        }
        else
            printf(" %d ", array[i]);
    }
}