/* 
 * File:   Dict.h
 * Author: jakeadicoff
 *
 * Created on March 27, 2015, 11:58 AM
 */

#ifndef DICT_H
#define	DICT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dict {
public:
    Dict();
    bool pfxSearch(string word, int lowIndex, int highIndex);
    bool binarySearch(string word, int lowIndex, int highIndex);
    // in lines for size and word at
    int size() {return (int)dictionary.size();}
    string at(int i) {return dictionary.at(i);}  
private:
    vector<string> dictionary;
};

#endif	/* DICT_H */

