/* 
 * File:   newfile.h
 * Author: jakeadicoff
 *
 * Created on February 17, 2015, 10:44 PM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define BUFFER_SIZE 40
    

typedef struct entry {
   char firstN[BUFFER_SIZE];
   char lastN[BUFFER_SIZE];
   char number[BUFFER_SIZE];
   char address[BUFFER_SIZE];
   int birthDay;
   int birthMonth;
   int birthYear;
   struct entry *next;
} entryType;

entryType* loadData(entryType *head);
entryType* insertEntry(entryType *entry, entryType *head);
void printLinks(entryType *head);
void freeMem(entryType *head);
void printEntry(entryType *head);
void searchName(entryType *head);
void searchMonth(entryType *head);
void searchMonth(entryType *head);
void searchRange(entryType *head);


#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

