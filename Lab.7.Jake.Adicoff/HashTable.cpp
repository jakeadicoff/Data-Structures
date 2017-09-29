/* 
 * File:   HashTable.cpp
 * Author: jakeadicoff
 * 
 * Created on April 29, 2015, 12:29 AM
 */

#include "HashTable.h"

HashTable::HashTable() {
    
}

HashTable::HashTable(int numBuckets) {
    if (numBuckets < 0) { // check inputs
        cerr << "Invalid number of buckets";
        return;
    }
    this->N = numBuckets; 
    this->table = new vector<Entry> [N]; // make hash table
    if (table == NULL) {
        cerr << "Allocation of hash table failed";
        return;
    }
    this->n = 0; 
}

Entry HashTable::insert(GameBoard board, int val) {
    this->n = n + 1; // increment numBoards for each insertion
    int hashVal, ind;
    Entry e(board, val); // make entry with key and value to be inserted
    hashVal = board.hashCode(); // make hash value
    ind = compress(hashVal); // compress hash value into an index
    table[ind].push_back(e); // add entry to vector with corresponding index
    return e; // return entry
}

int HashTable::compress(int hashVal) {
    // compress hash val into usable and unique index using mod function 
    // with prime numbers and numBuckets
    return ((((13 * hashVal) + 37) %16908799 ) % N );
}

Entry HashTable::find(GameBoard board) {
    bool found;
    int hashVal = board.hashCode(); // make hash val for board being searched
    int ind = compress(hashVal); // compress into index
    for (int i = 0; i < table[ind].size(); i++) {
        Entry e = table[ind].at(i); // search through bucket with index = ind
        found = board.equals(e.getBoard());
        if (found == true) {
            return e; // if found, returns entry
        }
    }
    // if not found, board with -1's and val = -99 created and returned
    GameBoard board1(-99);
    Entry e1(board1,-99);
    return e1;
}

Entry HashTable::remove(GameBoard board) {
    // same as find
    bool found;
    int hashVal = board.hashCode();
    int ind = compress(hashVal);
    for (int i = 0; i < table[ind].size(); i++) {
        Entry e = table[ind].at(i);
        found = board.equals(e.getBoard());
        if (found == true) {
            // if found, entry is erased before bing returned
            table[ind].erase(table[ind].begin() + i);
            return e;
        }
    }
    GameBoard board1(-99);
    Entry e1(board1,-99);
    return e1;
}

double HashTable::calcVariance() {
    // calc variance of items in each bucket. return double
    double var = 0;
    double loadf = getLoadFactor();
    for (int i = 0; i < N; i++) {
        int size = table[i].size();
        var += (size-loadf)*(size-loadf);
    }
    return (var/(N-1));
}

void HashTable::printListSize() {
    // prints size of each vector in arr
    for (int i = 0; i < N; i++) {
        cout << table[i].size() << endl;
    }
}

bool HashTable::isEmpty() {
    // check to see if empty
    for (int i = 0; i < N; i++) {
        if (table[i].size() > 0) {
            return false;
        }
    }
    return true;
}

void HashTable::makeEmpty() {
    for (int i = 0; i < N; i++) {
        table[i].clear();
    }
}

HashTable::~HashTable() {
    delete[] table;
}

