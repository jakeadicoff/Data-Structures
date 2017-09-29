/* 
 * File:   main.cpp
 * Author: jakeadicoff
 *
 * Created on February 26, 2015, 2:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "dict.h"
#include "puzzle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int wordLength; //min word length
    double start, end, seconds; //for timing 
    
    cout << endl << "WELCOME TO WORD SEARCH" << endl;
    cout << endl << "Enter minimum word length you want to search for: ";
    cin >> wordLength; 
    Puzzle puzz(wordLength); //creates puzzle object. dict created within puzzle
    puzz.printBoard();
   
    
    cout << endl << "------------------------------------------" << endl;
    
    cout << endl << "Using Naive search" << endl; //outputs
    start = clock();
    puzz.naiveSearch();
    end = clock();
    seconds = (end - start)/ CLOCKS_PER_SEC;
    cout << endl << "Run Time: " << seconds << " seconds" << endl;
    cout << "------------------------------------------" << endl;
    
    cout << endl << "Using Binary search" << endl;
    start = clock();
    puzz.binarySearch();
    end = clock();
    seconds = (end - start)/ CLOCKS_PER_SEC;
    cout << endl << "Run Time: " << seconds << " seconds" << endl;
    cout << "------------------------------------------"<< endl;
    
    
    cout << endl << "Using Binary search with prefixes" << endl;
    start = clock();
    puzz.prefBinarySearch();
    end = clock();
    seconds = (end - start)/ CLOCKS_PER_SEC;
    cout << endl << "Run Time: " << seconds << " seconds" << endl;
    cout << "------------------------------------------" << endl;
    
    return 0;
}

