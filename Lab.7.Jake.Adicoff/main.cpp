/* 
 * File:   main.cpp
 * Author: smajerci
 *
 * Created on November 18, 2014, 7:22 PM
 */

// Used 1 late day

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "GameBoard.h"
#include "HashTable.h"
#include "Entry.h"


using namespace std;

GameBoard randomBoard();
void initTable(HashTable &table, int numBoards);
bool allDiff(GameBoard boards[4]);
void printStats(int searches, int buckets, int boards);

int main(int argc, char** argv) {

    int numBoards = 10000;
    int numSearches = 2500000;
    cout << numBoards << " GameBoards inserted; "
            << numSearches << " searches" << endl << endl;
    
    
    // call printStats to get and print hash table stats w/ different numBuckets
    printStats(numSearches, 2000, numBoards);
    printStats(numSearches, 2222, numBoards);
    printStats(numSearches, 2500, numBoards);
    printStats(numSearches, 2857, numBoards);
    printStats(numSearches, 3333, numBoards);
    printStats(numSearches, 4000, numBoards);
    printStats(numSearches, 5000, numBoards);
    printStats(numSearches, 6666, numBoards);
    printStats(numSearches, 10000, numBoards);
    printStats(numSearches, 20000, numBoards);
    
    HashTable table(100); 
    // make an array of 4 GameBoards, all of which are different
    GameBoard boards[4];
    for (int i = 0; i < 4; ++i) {
        boards[i] = randomBoard();
    }
    while (allDiff(boards) == false) {
        for (int i = 0; i < 4; ++i) {
            boards[i] = randomBoard();
        }
    }
    
    table.insert(boards[0],1);
    table.insert(boards[1],2);
    
    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "ADDED BOARDS 1 AND 2 TO THE HASH TABLE" << endl << endl;
    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "SEARCHES AFTER INSERTIONS BUT BEFORE REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;


    cout << "Searching for Board 1 (which is in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    Entry e = table.find(boards[0]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (which is in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 3 (which is NOT in the hash table).  Board 3:" << endl << endl;
    boards[2].print();
    e = table.find(boards[2]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 4 (which is NOT in the hash table).  Board 4:" << endl << endl;
    boards[3].print();
    e = table.find(boards[3]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
    cout << "REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
    cout << "Removing Board 1 (which is in the hash table):" << endl << endl;
    boards[0].print();
    e =  table.remove(boards[0]);
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 2 (which is in the hash table):" << endl << endl;
    boards[1].print();
    e =  table.remove(boards[1]);
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 3 (which is NOT in the hash table):" << endl << endl;
    boards[2].print();
    e =  table.remove(boards[2]);
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 4 (which is NOT in the hash table):" << endl << endl;
    boards[3].print();
    e =  table.remove(boards[3]);
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    
    cout << "SEARCHES AFTER REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
        
    cout << "Searching for Board 1 (no longer in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    e = table.find(boards[0]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (no longer in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]);
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Call to isEmpty function returns:  " << table.isEmpty() << endl << endl;
    
    cout << "———————————————————------------------------————————" << endl << endl;

    return EXIT_SUCCESS;

}

GameBoard randomBoard() {
    GameBoard board;
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board.size(); x++) {
            double fval = rand() * 17;
            int value = (int) fval;
            board.setElementAt(x, y, value);
        }
    }
    return board;
}


void initTable(HashTable &table, int numBoards) {

    for (int i = 0; i < numBoards; i++) {
        table.insert(randomBoard(), i);
    }
}


bool allDiff(GameBoard boards[4]) {

    return
    !boards[0].equals(boards[1]) &&
            !boards[0].equals(boards[2]) &&
            !boards[0].equals(boards[3]) &&
            !boards[1].equals(boards[2]) &&
            !boards[1].equals(boards[3]) &&
            !boards[2].equals(boards[3]);
}

void printStats(int searches, int buckets, int boards) {
    double start, end, seconds;
    HashTable table(buckets); // make hash table with numBuckets 
    initTable(table, boards); // insert 10000 boards
    start = clock(); // get start time
    for (int i = 0; i < searches; i++) { // search for 2.5 mil rand boards 
        GameBoard board = randomBoard();
        table.find(board);
    }
    end = clock(); // get end time
    seconds = (end - start)/ CLOCKS_PER_SEC; // get total time
    // format and print stats
    cout << "Number buckets =";
    cout << setw(6) << table.getNumBuckets();
    cout << setw(17) << "Load factor = "; 
    cout << setw(4) << setprecision(2) << setiosflags(ios::fixed) << table.getLoadFactor();
    cout << setw(14) << "Variance = ";
    cout << setw(6) << setprecision(3) << setiosflags(ios::fixed) << table.calcVariance();
    cout << setw(10) << "Time = ";
    cout << setw(11) << setprecision(8) << setiosflags(ios::fixed) << seconds;
    cout << endl;
}