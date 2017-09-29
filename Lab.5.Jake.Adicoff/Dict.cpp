/* 
 * File:   Dict.cpp
 * Author: jakeadicoff
 * 
 * Created on March 27, 2015, 11:58 AM
 */

#include "Dict.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dict.h"

using namespace std;

Dict::Dict() {
    string dictFile;
    ifstream dictStream;
    
    do { //read file
        cout << endl << "enter dictionary file name: ";
        cin >> dictFile;
        dictStream.open(dictFile, ios::in);
    } while (!dictStream.good());
    
    string word;
    
    if (!getline(dictStream, word)) {
        cerr << "Error: dictionary file is empty" << endl;
        return; 
    }
    dictionary.push_back(word); //make vector of strings with dict words
    while (dictStream >> word) {
        dictionary.push_back(word);
    } 
}

// recursive code was adapted from my own python code from intro cs 
bool Dict::pfxSearch(string word, int lowIndex, int highIndex) {
    //recursive binary search w/ prefixes
    bool result; //returns if word is in dict
    string pref;
    int midIndex = (lowIndex + highIndex)/2; //get middle index of dict vector
    //base case
    if (highIndex < lowIndex) { // means word was not found
        return false; 
    } 
    pref = at(midIndex).substr(0,word.size());
    if (word == pref) {
        return true;
    }
    //recursive statement
    if (word < at(midIndex)) {
        return result = pfxSearch(word, lowIndex, midIndex-1);
    } else
        return result = pfxSearch(word, midIndex+1, highIndex);
}

bool Dict::binarySearch(string word, int lowIndex, int highIndex) {
    //recursive binary search
    bool result; //returns if word is in dict
    int midIndex = (lowIndex + highIndex)/2; //get middle index of dict vector
    //base case
    if (highIndex < lowIndex) { // means word was not found
        return false; 
    } 
    if (word == at(midIndex)) { // means word is found in dict
        return true;
    }
    //recursive statement
    if (word < at(midIndex)) {
        return result = binarySearch(word, lowIndex, midIndex-1);
    } else
        return result = binarySearch(word, midIndex+1, highIndex);
}


