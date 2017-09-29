/* 
 * File:   main.cpp
 * Author: jakeadicoff
 *
 * Created on March 27, 2015, 11:57 AM
 */

#include <cstdlib>
#include "Dict.h"
#include "Board.h"

using namespace std;

/* Used 1 late day on lab. turned in 4/11 at 10:30am
 * 
 */
int main(int argc, char** argv) {
    
    Board b;
    b.printBoard();
    b.game();
    
    return 0;
}

