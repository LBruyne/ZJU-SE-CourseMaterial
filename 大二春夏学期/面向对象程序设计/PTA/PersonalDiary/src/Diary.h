/*
* File: Diary.h
* Author: Xuanming, Liu
* Usage: Function declaration. 
* Latest revised: 2020.04.13             
*/

#ifndef _DIARY_H_
#define _DIARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// the file path for diary.txt
// which maintain the data.
#define FILE_PATH "Diary.txt"

class Diary{
private:
    string date;
    vector<string> text;

public:
    Diary(string);
    void reset();
	void addLine(string);
	int getTextSize();
	string getTextLine(int lineIndex);
    string getDate();
};

#endif