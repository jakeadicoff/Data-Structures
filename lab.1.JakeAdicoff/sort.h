/* 
 * File:   sort.h
 * Author: jakeadicoff
 *
 * Created on February 2, 2015, 9:21 PM
 */

#ifndef SORT_H
#define	SORT_H

#ifdef	__cplusplus
extern "C" {
#endif

void printArray(int *intArray, int numItems);
int positionMax(int *intArray, int startPlace, int numItems);
void selectionSort(int *intArray, int numItems);


#ifdef	__cplusplus
}
#endif

#endif	/* SORT_H */

