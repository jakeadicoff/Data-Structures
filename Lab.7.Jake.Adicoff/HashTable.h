/* 
 * File:   HashTable.h
 * Author: jakeadicoff
 *
 * Created on April 28, 2015, 7:39 PM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "Entry.h"
#include "GameBoard.h"

class HashTable {
public:
    HashTable();
    HashTable(int numBuckets);
    Entry insert (GameBoard board, int val);
    int compress(int hashVal);
    Entry find(GameBoard board);
    Entry remove(GameBoard board);
    bool isEmpty();
    void makeEmpty();
    double calcVariance();
    void printListSize();
    // in line getters
    int getNumBuckets() { return N;}
    int getNumItems() { return n;}
    float getLoadFactor() { return float(n)/N;}
    virtual ~HashTable();
private:
    // hash table is an arr of vectors 
    vector <Entry> * table;
    int n;
    int N;

};

#endif	/* HASHTABLE_H */

