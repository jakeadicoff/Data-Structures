/* 
 * File:   Entry.h
 * Author: smajerci
 *
 * Created on November 18, 2014, 7:38 PM
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include "GameBoard.h"
#include "Entry.h"

class Entry {
    
public:
    Entry();
    Entry(GameBoard board, int value);
    GameBoard getBoard() { return board; }
    int getValue() { return value; } 
    
private:
    
    GameBoard board;
    int value;
    
};

#endif	/* ENTRY_H */

