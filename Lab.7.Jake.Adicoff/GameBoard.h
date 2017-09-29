/* 
 * File:   GameBoard.h
 * Author: smajerci
 *
 * Created on November 18, 2014, 7:24 PM
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class GameBoard {
    
public:
    
    GameBoard();
    GameBoard(int val);
    void setElementAt(int x, int y, int value);
    int size() {return DIMENSION;}
    int elementAt(int x, int y) {return board[x][y];}
    bool equals(GameBoard board);
    int hashCode();
    void print();

private:
    
    static const int DIMENSION = 8;
    int board[DIMENSION][DIMENSION];

};

#endif	/* GAMEBOARD_H */

