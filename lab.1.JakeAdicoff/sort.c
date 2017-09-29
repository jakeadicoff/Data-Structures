/* 
 * File:   main.c
 * Author: jakeadicoff
 *
 * Created on January 29, 2015, 3:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/* sorts a list of randomly generated numbers with range from -100 to 100
 * using selection sort
 */

int main(int argc, char** argv) {
    int numItems;
    int *intArray; //pointer to array
    
    printf("Enter number of items you want to sort:\n");
    numItems = 0;
    scanf("%d", &numItems); //find num of items wanted in array
    intArray = (int *) malloc(numItems * sizeof(int));
    if (intArray == NULL) {
        printf("Error: malloc failed to execute");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    for (int i = 0; i < numItems; ++i) {  //populate array             
        intArray[i] = rand() %201 - 100; // get random int and add to array
    }
    printArray(intArray,numItems); //print unsorted array
    printf("\n");
    selectionSort(intArray,numItems); //sort array
    printArray(intArray, numItems); //print sorted array
    return (EXIT_SUCCESS);
}

void printArray(int *intArray, int numItems) {
    for (int i = 0; i < numItems; i++) {
    printf("%d ",intArray[i]);
    }  
}

void selectionSort(int *intArray, int numItems) {
    //sort list w/ selection sort using external positionMax function
    int maxPos;
    int firstNum;
    int maxNum;
    
    for (int i = 0; i < numItems; i++) { //iterate through array  
        maxPos = positionMax(intArray, i, numItems); /* find max in array of 
                                                      * modified length */
        firstNum = intArray[i]; //switch pos of max num and first num in array
        intArray[i] = intArray[maxPos];
        intArray[maxPos] = firstNum;   
    }
}

int positionMax(int *intArray, int startPlace, int numItems) {
    /*finds the position of the max in unsorted portion of array given a 
     * starting place within array*/
    int max;
    int maxPos;
    
    max = intArray[startPlace]; //set max == first num in array
    maxPos = startPlace; //make variable for position of max
    for (int i = startPlace; i < numItems; i++) {
        if (intArray[i] > max) {
            maxPos =i; //modify max pos if necessary
            max = intArray[i]; //also modify max so loop runs correctly
        }
    }     
    return maxPos; //return max pos to sort function

}