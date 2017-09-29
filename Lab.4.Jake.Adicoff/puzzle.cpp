/* 
 * File:   puzzle.cpp
 * Author: jakeadicoff
 * 
 * Created on February 26, 2015, 2:51 PM
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include "puzzle.h"
#include "dict.h"

using namespace std;

Puzzle::Puzzle(int wordLen) {
   // constructor 
   // code taken from lab hand out
   string fileName;
   ifstream puzzleStream;  
   
    do { // read in file
        cout << "Enter puzzle file name: ";
        cin >> fileName;
        puzzleStream.open(fileName, ios::in);
    } while (!puzzleStream.good());     
    string line;
     
    if (!getline(puzzleStream, line)) { //check to see if file is empty
        cerr << "Error: puzzle file is empty" << endl;
        numRows = 0;
        numCols = 0;
        return;
    }

   numCols = line.size(); // add first line to puzzle arr
    for (int i = 0; i < numCols; i++) {
        theBoard[0][i] = tolower(line.at(i));
    }
  
   for (numRows = 1; getline(puzzleStream, line); numRows++) {
        if (line.size() != numCols) { // check geometry 
            cerr << "Error: puzzle is not rectangular" << endl;
            numRows = 0;
            numCols = 0;
            return;
    }
        for (int i = 0; i < numCols; i++) { // add all other lines to puzzle
            theBoard[numRows][i] = tolower(line.at(i));
        }
    }
   this->minLen = wordLen; // set min word length
}

void Puzzle::printBoard() {
    cout << endl << "Dictionary Size: " << dictionary.size() << " words";
    cout << endl << "Puzzle Size: " << numRows << " Rows, and " 
            << numCols << " columns" << endl << endl;
    for (int i = 0; i < numRows; i++) {
        cout << "  ";
        for (int j = 0; j < numCols; j++) {
            cout << " " << theBoard[i][j];
        }
        cout << endl;
       
    }
}

int Puzzle::naiveSearch() { // returns int so that function can be exited easily
// first, a quick joke:
//what does a pig put on its rash...
    
    vector<string> wordList;
    minLen = minLen - 1;
    
    if (minLen > numCols || minLen > numRows) { // check  if minLen valid
        return 0;  
    } 
    
    int maxLen; // for non square puzzle boards 
    if (numRows > numCols) {
        maxLen = numRows;
    } else {
        maxLen = numCols;
    }
    
    for (int i = 0; i < dictionary.size(); i++) { 
        // iterate through indexes in dict
          
        if (dictionary.at(i).size() > minLen ) {
            //check if they meet min length. if not, continue
            
            string dWord = dictionary.at(i); //get word at index
            string pWord; // to save word made in puzzle 
            string fL; //saves first letter
            
            int wLen = dWord.size(); //get dict word length
            
            
            for (int r = 0; r < numRows; r++) {
                
                for (int c = 0; c < numCols; c++) {
                    //iterate through all rows and cols
                    
                    fL = dWord.substr(0,1);
                    pWord = theBoard[r][c];
                    
                    if (fL == pWord) { 
                        // check to see if first letters match. if not, continue
                        
                        
                        for (int y = -1; y < 2; y++){
                        
                            for (int x = -1; x < 2; x++) {
                                // ints for 9make directions 
                                
                                if (x == 0 && y == 0) {
                                    continue;
                                } // continue through 0,0 direction
                                
                                pWord = theBoard[r][c];
                                int vRange, hRange;
                                
                                // next lines determine if a word can exist... 
                                // in a specific direction without exiting...
                                // the board boundries
                                hRange = r + (wLen-1) * x; 
                                vRange = c + (wLen-1) * y;
                                if (vRange < 0 || hRange < 0) {
                                    continue;
                                }
                                if (hRange > numCols || vRange > numRows) {
                                    continue;
                                }
                                // loop builds words 1 letter at a time for//
                                // each direction
                                for (int n = 1; n < wLen; n++){
                                    
                                    int hInd, vInd;
                                    
                                    hInd = r + n * x;
                                    vInd = c + n * y; 
                                    pWord = pWord + theBoard[hInd][vInd];  
                                }
                                if (pWord == dWord) { // check dict for word
                                    wordList.push_back(pWord); 
                                    // found words added to list
                                }    
                            }
                        }
                    } else {
                        continue;
                    }
                        
                }
            }  
        }
    }

    for (int z = 0; z < wordList.size(); z++) { // list of found words printed
        cout << endl << "Found: " << wordList[z];
    }
    cout << endl << endl << "Found " << wordList.size() << " matches";
    
    //...oinkment! 
}


int Puzzle::binarySearch() {
    
    vector<string> wordList;
    string pWord;
    int maxH;
    int maxV;
    
    //iterate through rows and cols
    for (int c = 0; c < numCols; c++) {
        
         for (int r = 0; r < numRows; r++) {
            //make directions
            for (int x = -1; x < 2; x++) {
                
                for (int y = -1; y < 2; y++) {
                    //initialize word to letter at r and c index
                    pWord = theBoard[c][r];
                    //skip 0,0 direction
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    
                    int a = 0;//for infinite while loop
                    int maxD = 1;
                    //while loop checks to see how far you can move in one...
                    // direction without going outside the board. number...
                    // stored in maxD (maxDirection)
                    while (a == 0) { 
                        maxH = c + y*maxD;
                        maxV = r + x*maxD;
                        maxD++;
                        if (maxV <= 0 || maxH <= 0) {
                            break;
                        }
                        if (maxV >= numRows || maxH >= numCols) {
                            break;
                        }
                    }
                    // makes sure there is room for min length in the direction
                    if (maxD+1 < minLen) { 
                        continue;
                    }   
                    // builds words for each valid direction and for as many
                    // letters you can move in that direction without 
                    // leaving board
                    for (int n = 1; n < maxD; n++) {
                        bool w = false;
                        int hInd, vInd;
                        hInd = c + y * n;
                        vInd = r + x * n;
                        pWord = pWord + theBoard[hInd][vInd];  
                        // checks word with binary search function 
                        w = dictionary.binarySearch(pWord,0,dictionary.size());
                        // if word and long enough, its added to found word list 
                        if (w == true && pWord.size() > minLen) {
                            wordList.push_back(pWord);
                        }           
                    }
                }
            }     
         }
    }
    for (int z = 0; z < wordList.size(); z++) {
        cout << endl << "Found: " << wordList.at(z);
    }
    cout << endl << endl << "Found " << wordList.size() << " matches";    
    
}

int Puzzle::prefBinarySearch() {
    // exact same as original binary search except for in final for loop
    vector<string> wordList;
    string pWord;
    int maxH;
    int maxV;
    
    
    for (int c = 0; c < numCols; c++) {
        
         for (int r = 0; r < numRows; r++) {
            
            for (int x = -1; x < 2; x++) {
                
                for (int y = -1; y < 2; y++) {
                    
                    pWord = theBoard[c][r];
                    
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int a = 0;
                    int maxD = 1;
                    
                    while (a == 0) {
                        maxD++;
                        maxH = c + y*maxD;
                        maxV = r + x*maxD;
                        if (maxV <= 0 || maxH <= 0) {
                            break;
                        }
                        if (maxV >= numRows || maxH >= numCols) {
                            break;
                        }
                    }
                    
                    if (maxD+1 < minLen) {
                        continue;
                    }   
                    
                    for (int n = 1; n < maxD; n++) {
                        bool w = false;
                        int hInd, vInd;
                        hInd = c + y * n;
                        vInd = r + x * n;
                        pWord = pWord + theBoard[hInd][vInd]; 
                        w = dictionary.isPrefix(pWord,0,dictionary.size());
                        if (w == false) { // check to see if prefix is valid
                            continue; // if not, continue
                        }
                        if (w == true && pWord.size() > minLen) {
                            wordList.push_back(pWord); // if word meets min and
                            // is valid, added to found words vector
                        }    
                    }
                }
            }     
         }
    }
   
    for (int z = 0; z < wordList.size(); z++) {
        cout << endl << "Found: " << wordList.at(z);
    }
    cout << endl << endl << "Found " << wordList.size() << " matches";    
    
}

