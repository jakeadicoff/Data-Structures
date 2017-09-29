/* 
 * File:   main.cpp
 * Author: jakeadicoff
 *
 * Created on April 12, 2015, 2:49 PM
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

/*
 * 
 */
int main(int argc, char** argv) {
    
    Sudoku s;
    s.solve();
    
    return 0;
}

