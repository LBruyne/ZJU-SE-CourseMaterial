/*
* File: Diary.cpp
* Author: Xuanming, Liu
* Usage: Defining function in Diary.h
* Latest revised: 2020.04.13             
*/

#include "Diary.h"

Diary::Diary(string D)
{
	date = D;
}

void Diary::addLine(string line)
{
	text.push_back(line);
}

void Diary::reset()
{
	text.clear();
}

string Diary::getDate()
{
	return date;
}

int Diary::getTextSize()
{
    return text.size();
}

string Diary::getTextLine(int lineIndex)
{
    return text[lineIndex];
}