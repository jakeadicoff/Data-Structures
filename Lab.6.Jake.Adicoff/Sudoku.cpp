/* 
 * File:   Sudoku.cpp
 * Author: jakeadicoff
 * 
 * Created on April 12, 2015, 4:09 PM
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


using namespace std;

Sudoku::Sudoku() {
    
}

void Sudoku::solve() {
    bool solved = false; // for infinite while loop
    while (solved == false) {
        Move m(theBoard.nextMove(1)); // make move object with legal move
        if (m.val() != 0) { // if there is legal move, m.val will be a int 1 - 9
            solutions.push(m); // push move onto stack
            theBoard.setValue(m.row(),m.col(),m.val()); // change board
        } else {
            while (m.val() == 0) { // if m.val == 0, no legal move...
                // and moves need to be poped off stack until there is a legal move
                Move topM = solutions.top(); // save top move on stack
                solutions.pop(); // pop top move
                
                theBoard.setValue(topM.row(),topM.col(),0); 
                // reset 0 on board using topM
                if (topM.val() == 9) {
                    topM.setVal();
                    m = topM;
                    continue;
                }
                // make next legal move with incremented value
                m = (theBoard.nextMove(topM.val()+1));
                
            }
            // when there is a legal move, it is pushed onto stack and board 
            // is modified
            theBoard.setValue(m.row(),m.col(),m.val());
            solutions.push(m);
        }
        // check to see if solved
        solved = theBoard.success();
        if (solved == true) {
            cout << endl << endl << "  Solved!";
            break;
        }
    }
    cout << endl << endl;
    theBoard.printBoard();
}