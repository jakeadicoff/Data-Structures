/* 
 * File:   Move.h
 * Author: jakeadicoff
 *
 * Created on April 12, 2015, 4:08 PM
 */

#ifndef MOVE_H
#define	MOVE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stack>

using namespace std;

class Move {
public:
    Move();
    Move(int row, int col,int val);
    int row() { return r;} // getters for values
    int col() { return c;}
    int val() { return value;}
    bool setVal() {this->value = 0;} // sets move object value == 0. 
    // see sudoku.cpp while loop. if val == 9 and board state illegal. set to 0
    
private:
    int r;
    int c;
    int value;
};

#endif	/* MOVE_H */

