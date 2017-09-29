/* 
 * File:   main.c
 * Author: jakeadicoff
 *
 * Created on February 8, 2015, 5:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newfile.h"

/* Used 2 late days for lab. Turned in to black board 2/21
 * 
 */

int main(int argc, char** argv) {
    
    //head of linked list. set to null until entries are added
    entryType *head = NULL;
    //load data from input file. function also calls insert node function
    head = loadData(head);
    //search functions. use head to access linked list
    searchName(head);
    searchMonth(head);
    searchRange(head);
    //uncomment to print all entries in linked list
    //printLinks(head); 
    freeMem(head);
    return (EXIT_SUCCESS);
}


entryType* loadData(entryType *head) {   
    
    FILE *inputf;
    char buffer[100];
    entryType *entry;
    
    inputf = fopen("adrsInput.txt", "r");
    if(inputf == NULL) {
        printf("Malloc for file pointer failed to execute");
        return NULL;             
    }
    
    // scan in data from input file using for loop 
    // insert node function heald within while loop
    while (fgets(buffer,100,inputf) != NULL) {
        
        entry = (entryType*) malloc(sizeof(entryType));
        if(entry == NULL) {
            printf("malloc failed to execute");
            return NULL;
        }
        
        // scan input from file. store in entry struct
        sscanf(buffer, "%[^,], %[^,], %[^,], %[^,], %d, %d, %d",
                entry ->firstN,
                entry ->lastN,
                entry ->number,
                entry ->address,
                &entry ->birthMonth,
                &entry ->birthDay,
                &entry ->birthYear); 
        
        entry ->next = NULL; // set the pointer held within entry == null
        
        //checking for valid birth day/month/year values
        if(entry->birthDay > 31) { 
            printf("\nBirthday of %s %s is invalid\n", 
                    entry->firstN, entry->lastN);
            return NULL;
        }
        if(entry->birthMonth > 12) {
            printf("\nBirth Month of %s %s is invalid\n", 
                    entry->firstN, entry->lastN);
            return NULL;
        }
        if(entry->birthYear > 2015) {
            printf("\nBirth Year of %s %s is invalid\n", 
                    entry->firstN, entry->lastN);
            return NULL;
        }
        
        //insert entries into linked list 
        head = insertEntry(entry,head);
            
    }
    //return head to main function so linked list can be used
    return head;  
}


entryType* insertEntry(entryType *entry, entryType *head) {
    
    //hold values for pointer rearranging 
    entryType *curr; 
    entryType *prev; 
    int dif; // for strcmp values
    
    // 5 cases for entry insertion into linked list. all return head to...
    // ...loadData function
  
    // first case: no links in list yet. set head == entry 
    if (head == NULL) {
        head = entry;
        return head;
    }
    
    curr = head->next;
    prev = head;
    
    // 2nd case: one entry in list. see which side of link new entry belongs on
    if (head->next == NULL) {
        dif = strcmp(entry->lastN,head->lastN);
        if (dif < 0) {
            head = entry;
            entry->next = curr;
            return head;
        } else {
            head->next = entry;
            return head;
        }     
    }
    
    // 3rd case: new entry belongs between head and previous first entry
    dif = strcmp(entry->lastN,head->lastN);
    if(dif < 0) { //if entry will be first in list, change head
        entry->next = head;
        head = entry;
        return head;     
    }
    
    // 4th case: new entry to be inserted within list
    while (curr->next != NULL) {
        
        dif = strcmp(entry->lastN, curr->lastN);
        if(dif < 0) {
            entry->next = prev->next;
            prev->next = entry;
            return head;         
        }
        if(dif == 0) {
            entry->next = prev->next;
            prev->next = entry;
            return head; 
        }
        //advance values of prev and curr for while loop operation
        prev = curr;
        curr = curr ->next;
        
    }
    
    // 5th case: new entry belongs at very end of list
    if (curr->next == NULL) {
        curr->next = entry;
        return head;
    }
}

void printEntry(entryType *entry) {
    printf(" Name: %s %s \n Number: %s \n Address: %s "
            "\n Birthday: %d/%d/%d\n----------------------------- \n", 
                entry->firstN, entry->lastN, 
                entry->number, 
                entry->address, 
                entry->birthMonth, entry->birthDay, entry->birthYear);
}


void searchName(entryType *head) {
    char searchN[20];
    printf("\nSearch by last name (use upper case for 1st letter):\n");
    scanf("%s", searchN); //user input
     
    entryType *curr = head;
    int dif;
    
    while(curr->next != NULL) { 
        dif = strcmp(curr->lastN,searchN); //compare input and last name in curr
        if(dif == 0) {
            printEntry(curr); // print all matches
        }
        curr = curr->next;
    }
}


void searchMonth(entryType *head)  {
    int searchM;
    entryType *curr = head;
    
    // search by month of birth
    printf("\nEnter month to search (1-12)\n");
    scanf("%d",&searchM); // scan user input
    
    if(searchM > 12 && searchM < 1) { // check for valid month value
        printf("\nInvalid month\n");
    } else {
        while(curr != NULL) {
            if(curr->birthMonth == searchM){
            printEntry(curr); //print all entries w/ correct month value
        }
        curr = curr->next;
        }
    } 
}


void searchRange(entryType *head) {
    char searchA[2]; //for first char in range
    char searchB[2]; //for last char in range
    int dif; //for string compare
    
    entryType *curr = head;
    
    printf("\nEnter beginning letter (capital) of range you want to search:\n");
    scanf("%s",searchA);
    printf("\nEnter end letter (capital) of range you want to search:\n");
    scanf("%s",searchB);
    
    while(curr != NULL) {
        dif = strcmp(curr->lastN,searchA);
        if(dif > 0) { // if first char > name
            dif = strcmp(curr->lastN,searchB);
            if(dif <= 0) { // if last char < name...
                printEntry(curr); // then entry in range and will be printed
            } 
        }
        curr = curr->next;
    }   
}


void printLinks(entryType *head) {
    while(head != NULL) {
        printf(" Name: %s %s \n Number: %s \n Address: %s "
                "\n Birthday: %d/%d/%d\n----------------------------- \n", 
                head->firstN, head->lastN, 
                head->number, 
                head->address, 
                head->birthMonth, head->birthDay, head->birthYear);
        head = head->next;
    }         
}


void freeMem(entryType *head) {
    entryType *curr;
    curr = head;  
    while(curr != NULL) {
        head = curr;
        curr = curr->next;
        free(head);
    }
}