/* 
 * File:   Sudoku.h
 * Author: jakeadicoff
 *
 * Created on April 12, 2015, 4:09 PM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stack>
#include "Move.h"
#include "Board.h"

using namespace std;

class Sudoku {
public:
    Sudoku();
    void solve();
    
private:
    Board theBoard;
    std::stack<Move> solutions;
    static const int DIM = 9;
};

#endif	/* SUDOKU_H */

