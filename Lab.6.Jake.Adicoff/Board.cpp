/* 
 * File:   Board.cpp
 * Author: jakeadicoff
 * 
 * Created on April 12, 2015, 4:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stack>
#include "Sudoku.h"
#include "Board.h"

using namespace std;

Board::Board() {
   // constructor 
   // code taken from lab hand out
   string fileName;
   ifstream puzzleStream;  
   
    do { // read in file
        cout << "Enter board file name: ";
        cin >> fileName;
        puzzleStream.open(fileName, ios::in);
    } while (!puzzleStream.good());     

    int rows = 0; // for checking dimensions
    int cols = 0;
    
    for (int r = 0; r < DIM; r++) {
        rows += 1;
        cols = 0;
        for (int c = 0; c < DIM; c++) {
            puzzleStream >> theBoard[r][c];// read in ints
            cols += 1;
        }
        if (cols != 9) { // make sure dimensions are legal
            cerr << "Error: sudoku file does not contain legal dimensions" << endl;
            return;
        }
    }
    if (rows != 9) {
        cerr << "Error: sudoku file does not contain legal dimensions" << endl;
        return;
    }
    cout << endl << "  Unsolved Sudoku board" << endl << endl;
    printBoard();
}

void Board::printBoard() {
    
    for (int r = 0; r < DIM; r++) {
        cout << "  ";
        for (int c = 0; c < DIM; c++) {
            if (theBoard[r][c] == 0) {
                cout << "_" << " ";
            } else {
                cout << theBoard[r][c] << " ";
            }
            if ((c+1)%3 == 0 && c != 8) {
                cout << "| ";
            }
        }
        if ((r+1)%3 == 0 && r != 8) {
            cout << endl << "  ----------------------"; 
        }
        cout << endl;
    } 
}

// checks to see if there are any 0's left in board. if none, returns true
bool Board::success() { 
    bool solved = true;
    for (int r = 0; r < DIM; r++) {
        for (int c = 0; c < DIM; c++) {
            if (theBoard[r][c] == 0) {
                solved = false;
                return solved;
            }
        }
    }
    return true;
}


// returns next legal move. takes num as a parameter so numbers in a single spot
// on the board can be incrimented 
Move Board::nextMove(int num) {
    int boardState[RC][RC];
    bool legalMove;
    for (int r = 0; r < DIM; r++) { 
        for (int c = 0; c < DIM; c++) {
            if (theBoard[r][c] == 0) { // find the first 0 in board
                for (int a = 0; a < DIM; a++) {
                    for (int b = 0; b < DIM; b++) { 
                        // make board copy to give to islegal function
                        boardState[a][b] = theBoard[a][b]; 
                    }
                } 
                // insert possible nums 1 - 9 into board position
                for (int n = num; n < 10; n++) {
                    boardState[r][c] = n;
                    legalMove = isLegal(r, c, boardState);
                    // if move is legal, move object is created and returned
                    if (legalMove == true) {
                        Move m(r,c,n);
                        return m;
                    }
                    // if no legal move, move object with value == 0 is returned
                    if (n == 9) {
                        Move m(0,0,0);
                        return m;
                    }
                }
            } else {
                continue;
            }
        }
    }
}

// check to see if board state is a legal sudoku board 
// returns true if legal
bool Board::isLegal(int targR, int targC, int boardState[RC][RC]) {
    bool legal = true;
    // check for repeat numbers in row
    for (int r = 0; r < DIM; r++) {
        if (r == targR) {
            continue;
        } else {
            if (boardState[r][targC] == boardState[targR][targC]) {
                legal = false;
                return legal;
            }
        }
    }
    // check for repeat numbers in col
    for (int c = 0; c < DIM; c++) {
        if (c == targC) {
            continue;
        } else {
            if (boardState[targR][c] == boardState[targR][targC]) {
                legal = false;
                return legal;
            }
        }
    }
    // check for repeat numbers in each 3x3 cell
    int indR, indC;
    if (targR < 3 && targC < 3) {
        indR = 0;
        indC = 0;
    }
    else if (targR < 3 && targC > 2 && targC < 6) {
        indR = 0;
        indC = 3;
    }
    else if (targR < 3 && targC > 5) {
        indR = 0;
        indC = 6;
    }
    else if (targR > 2 && targR < 6 && targC < 3) {
        indR = 3;
        indC = 0;
    }
    else if (targR > 2 && targR < 6 && targC > 2 && targC < 6) {
        indR = 3;
        indC = 3;      
    }
    else if (targR > 2 && targR < 6 && targC > 5) {
        indR = 3;
        indC = 6;
    }
    else if (targR > 5 && targC < 3) {
        indR = 6;
        indC = 0;
    }  
    else if (targR > 5 && targC > 2 && targC < 6) {
        indR = 6;
        indC = 3;
    }
    else if (targR > 5 && targC > 5) {
        indR = 6;
        indC = 6;
    }
    for (int r = indR; r < indR+3; r++) {
        for (int c = indC; c < indC+3; c++) {
            if (targR == r && targC == c) {
                continue;
            } else {
                if (boardState[targR][targC] == boardState[r][c]) {
                    legal = false;
                    return legal;
                }
            }  
        }
    }
    return legal;
}
