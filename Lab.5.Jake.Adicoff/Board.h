/* 
 * File:   Board.h
 * Author: jakeadicoff
 *
 * Created on March 28, 2015, 1:21 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dict.h"
#include "Board.h"


using namespace std;

class Board {
public:
    Board();
    void printBoard();
    void game();
    void usrGame();
    bool findAllWordsRec(char board[6][6], int r, int c, string word);
    void findAllWords();
    void printVect(vector <string> words);
    int score(vector <string> words);
    
    
private:
    Dict dictionary;
    static const int MAX_ROWS = 6;
    static const int MAX_COLS = 6;
    char theBoard[MAX_ROWS][MAX_COLS];
    int numCols;
    int numRows;
    vector <string> usrWords; // vectors to hold usr and comp words 
    vector <string> compWords;
};

#endif	/* BOARD_H */

