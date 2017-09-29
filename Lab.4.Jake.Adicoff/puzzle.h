/* 
 * File:   puzzle.h
 * Author: jakeadicoff
 *
 * Created on February 26, 2015, 2:51 PM
 */

#ifndef PUZZLE_H
#define	PUZZLE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dict.h"


using namespace std;

class Puzzle {
public:
    Puzzle(int wordLen);
    void printBoard();
    int naiveSearch();
    int binarySearch();
    int prefBinarySearch();
    
private:
    dict dictionary;
    static const int MAX_ROWS = 50;
    static const int MAX_COLS = 50;
    char theBoard[MAX_ROWS][MAX_COLS];
    int numCols;
    int numRows;
    int minLen;
};

#endif	/* PUZZLE_H */

