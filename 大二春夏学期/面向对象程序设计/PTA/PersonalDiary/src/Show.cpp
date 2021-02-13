/*
 * File: Show.cpp
 * Author: Xuanming, Liu
 * Usage: 
 * Here we achieve the pdshow function.
 * Latest revised: 2020.04.13             
**/

#include "Diary.h"
using namespace std;

int main(int argc, char* argv[])
{
    ifstream fileIn(FILE_PATH);
    string date, text;
    vector<Diary*> DiaryBook;
    // similar to Add.cpp and others.
    while(!fileIn.eof()){
        getline(fileIn, date);
        Diary* diary = new Diary(date);
        getline(fileIn, text);
        while(text != "."){
            diary->addLine(text);
            getline(fileIn, text);
        }
        DiaryBook.push_back(diary);
    }
    fileIn.close();

    // Simply find the date and print it.
    date = argv[1];
    for(int i = 0; i < DiaryBook.size(); i++){
        if(date == DiaryBook[i]->getDate()){
            for(int j = 0; j < DiaryBook[i]->getTextSize(); j++)
                cout << DiaryBook[i]->getTextLine(j) << endl;
            break;
        }
    }  
    return 0;
}