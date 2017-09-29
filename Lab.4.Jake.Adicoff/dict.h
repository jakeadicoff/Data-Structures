/* 
 * File:   dict.h
 * Author: jakeadicoff
 *
 * Created on February 26, 2015, 2:51 PM
 */

#ifndef DICT_H
#define	DICT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class dict {
public:
    dict();
    bool binarySearch(string word, int lowIndex, int highIndex);
    bool isPrefix(string word, int lowIndex, int highIndex);
    // in lines for size and word at
    int size() {return (int)dictionary.size();}
    string at(int i) {return dictionary.at(i);}  
private:
    vector<string> dictionary;       
};

#endif	/* DICT_H */

