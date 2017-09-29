/* 
 * File:   Board.h
 * Author: jakeadicoff
 *
 * Created on April 12, 2015, 4:08 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stack>

using namespace std;

class Board {
public:
    Board();
    void printBoard();
    int returnValue(int r, int c) {return theBoard[r][c];}
    void setValue(int r, int c, int value) { theBoard[r][c] = value;}
    bool success();
    bool isLegal(int targR, int targC, int boardState[10][10]);
    Move nextMove(int num);
    
    
private:
    static const int DIM = 9;
    static const int RC = 10;
    int theBoard[RC][RC];
};

#endif	/* BOARD_H */

