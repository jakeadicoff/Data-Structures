/* 
 * File:   Move.cpp
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
#include "Move.h"


using namespace std;

Move::Move() {
    
}

Move::Move(int row, int col, int val) {
    this->r = row;
    this->c = col;
    this->value = val;
}



