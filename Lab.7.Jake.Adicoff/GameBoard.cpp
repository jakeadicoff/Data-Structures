/* 
 * File:   GameBoard.cpp
 * Author: smajerci
 * 
 * Created on November 18, 2014, 7:24 PM
 */

#include "GameBoard.h"


GameBoard::GameBoard() {
}

GameBoard::GameBoard(int val) {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            board[r][c] = -1;
        }
    }
}

void GameBoard::setElementAt(int x, int y, int value) {
    board[x][y] = value % 3;
    if (board[x][y] < 0) {
        board[x][y] = board[x][y] + 3;
    }
}

void GameBoard::print() {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool GameBoard::equals(GameBoard board) {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (this->board[r][c] != board.elementAt(r, c))
                return false;
        }
    }
    return true;
}


int GameBoard::hashCode() {
    // compute unique hash value for a board
    // uses code from class modified for a 2D array of ints
    int hashVal = 0;
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            hashVal = (127*hashVal+board[r][c]) % 16908799;
        }
    }
    return hashVal;
}

