/* 
 * File:   Board.cpp
 * Author: jakeadicoff
 * 
 * Created on March 28, 2015, 1:21 PM
 */

//#include "Board.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include "Board.h"
#include "Dict.h"

using namespace std;

Board::Board() {
   // constructor 
   // code taken from lab hand out
   string fileName;
   ifstream puzzleStream;  
   
    do { // read in file
        cout << "Enter board file name: ";
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

   numCols = line.size(); // add first line to board arr
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
        for (int i = 0; i < numCols; i++) { // add all other lines to board
            theBoard[numRows][i] = tolower(line.at(i));
        }
    }
}



void Board::printBoard() { // print boggle in upper case
    cout << endl << "Dictionary Size: " << dictionary.size() << " words" 
            << endl << endl;

    for (int i = 0; i < numRows; i++) {
        cout << "  ";
        for (int j = 0; j < numCols; j++) {
            char c = theBoard[i][j];
            c = (toupper(c));
            cout << " " << c;
        }
        cout << endl;
    }
}

void Board::game() { // runs boggle game, similar to a main function, but easier
    // to format within the class
    
    int usrScore, compScore; //variables for score
    string play; 
    findAllWords(); // start by comp finding all words in board
    
    cout << endl << "Do you want to play Boggle? (type y or n)" << endl;
    cin >> play; 
    if (play == "y") {
        usrGame(); // user plays if they choose to
        cout << "Your legal words were: " << endl << endl;
        printVect(usrWords); // vec of usr words is printed 
        usrScore = score(usrWords); // vec of usr words is scored 
        cout << endl << "Your total score is: " << usrScore;     
    }
    
    cout << endl << "--------------------------------" << endl << endl;
    cout << "The words the computer found are: " << endl << endl;
    printVect(compWords); // vec of comp words is printed 
    compScore = score(compWords); // vec of usr words is scored  
    compScore = compScore - usrScore; // score reduction for usr words
    cout << endl << "The computer's total score is: " << compScore;
    cout << endl << "(excludes words you found)" << endl << endl;  
    cout << endl << compWords.size();
}

void Board::usrGame() {
    //human game. take string inputs and check if in board and dict
    //valid words are added to vector of strings for scoring
    bool inB, inD, prevUse; // to tell if words are legal
    string input;
    cout << endl << "Enter a word followed by 'return'" << endl;
    cout << "When you're done entering words, type '!' and press 'return'";
    cout << endl << "---------------------------------------------------------"; 
    cout << endl << endl;
    while (input != "!") { // infinite loop
        cout << endl;
        cin >> input; // take input word from usr
        if (input =="!") {
            continue;
        }
        
        inB = false; // check if in board (in compWords vector)
        for (int a = 0; a < compWords.size(); a++) {
            if (input == compWords.at(a)) {
                inB = true;
            }
        }
        if (inB == false) {
            cout << endl << "   Invalid word: not in the board ";
        }
        inD = false; // check if in dictionary with dictionary binary search
        inD = dictionary.binarySearch(input,0,dictionary.size());
        if (inD == false) {
            cout << endl << "   Invalid word: not in the dictionary ";
        }
        
        if (input.size() < 3){ // check to see if long enough
            cout << endl << "   Invalid word: too short. ";
        }
        prevUse = false; // check to see if word was previously entered
        if (usrWords.size() > 0) {
            for (int i = 0; i < usrWords.size(); i++) {
               if ( usrWords.at(i) == input) {
                    prevUse = true;
                    cout << endl << "   Invalid word: already been used ";      
                }
            }
        }
        // if all conditions are met, word is added to usrWords vector
        if (inB == true && inD == true && prevUse == false && input.size() > 2) {
            usrWords.push_back(input);
            cout << endl << "   Good word! ";
        }
        
    }
       
}



void Board::findAllWords() {
    //computer game. finds all words returns string vector of words
    char boardCopy[MAX_ROWS][MAX_COLS]; // for board copy
    string word = ""; // to send to rec function 
    for (int r = 0; r < numRows; r++){ // iterate through all rows and cols
        for (int c = 0; c < numCols; c++) {
            for (int a = 0; a < numRows; a++) { // make board copy
                for (int b = 0; b < numCols; b++) {
                    boardCopy[a][b] = theBoard[a][b];
                } 
            }
            findAllWordsRec(boardCopy,r,c,word); // send board copy to rec function
        }
    }
}

bool Board::findAllWordsRec(char board[MAX_ROWS][MAX_COLS], int r, int c, string word) {
    
    bool isPrefix;
    bool isWord;
    char boardCopy[MAX_ROWS][MAX_COLS];
    
    // base case 1: outside board
    if(r < 0 || c < 0 || r > numRows || c > numCols) {
        return false;
    }
    // base case 2: already used letter
    if (board[r][c] == ' ') {
        return false;
    }
    
    if (board[r][c] == 'q') { // check for 'q' case
        word = word + "qu";
    } else {
        word = word + board[r][c]; // add letter to construct possible words
    }
    // checks to see if word is prefix in dictionary
    isPrefix = dictionary.pfxSearch(word,0,dictionary.size()); 
    // base case 3: if word is prefix, it is tested to see if legal word and
    // then added to compWords vect. if word is not a prefix, returns flase
    if (isPrefix == true) {
        isWord = dictionary.binarySearch(word,0,dictionary.size());
        if (isWord == true && word.size() > 3) {
            bool prevUse = false;
            if (compWords.size() == 0) {   
                compWords.push_back(word);  
            } else {
                for (int q = 0; q < compWords.size(); q++) {
                    if (word == compWords.at(q)) {
                        prevUse = true;
                    }
                }
                if (prevUse == false) {
                    compWords.push_back(word);
                }
            }
        }
    } else {
        return false;
    }
    
    // 'erases' used letters
    board[r][c] = ' ';
    
    for (int x = -1; x < 2; x++) { // iterate through all directions 
        for (int y = -1; y < 2; y++) {
                // makes another board copy to send to rec function
                for (int a = 0; a < numRows; a++) { 
                    for (int b = 0; b < numCols; b++) {
                        boardCopy[a][b] = board[a][b];
                    }
                // recursive call with modified r and c
                findAllWordsRec(boardCopy,r+x,c+y,word); 
            }
        }
    }
}


void Board::printVect(vector <string> words) {// prints sorted vector of strings
    sort(words.begin(), words.end()); 
    for (int i = 0; i < words.size(); i++) {
        cout << words.at(i) << endl;
    }
}

int Board::score(vector <string> words) { // scores vector of strings
    int score = 0;
    string word;
    int wordS;
    // iteraate through string vector
    for (int i = 0; i < words.size(); i++) {
        word = words.at(i);
        wordS = word.size();
        // add to score based on word size
        if (wordS == 3 || wordS == 4) {
            score = score + 1;
            continue;
        }
        if (wordS == 5) {
            score = score + 2;
            continue;
        }
        if (wordS == 6) {
            score = score + 3;
            continue;
        }
        if (wordS == 7) {
            score = score + 5;
            continue;
        }
        if (wordS <= 8) {
            score = score + 11;
        }
    }
    return score;
}