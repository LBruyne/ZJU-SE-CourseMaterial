/*
 * File: List.cpp
 * Author: Xuanming, Liu
 * Usage: 
 * Here we achieve the pdlist function.
 * Latest revised: 2020.04.13             
**/

#include "Diary.h"
using namespace std;

int main(int argc, char* argv[])
{
    ifstream fileIn(FILE_PATH);
    string date, text, beginDt, endDt;
    vector<Diary*> DiaryBook;
    int i;

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

    // if there is 1 parameter.
    if(argc == 1)
        // list all Diaries.
        for(i = 0; i < DiaryBook.size(); i++){
            cout << DiaryBook[i]->getDate() << endl;
            cout << DiaryBook[i]->getTextLine(0) << endl;
        }
    // if there are 3 parameters, which means containing 2 date.
    else if(argc == 3){
        // get the begin date and end date.
        beginDt = argv[1];
        endDt = argv[2];
        // display the diary between the two dates.
        for(i = 0; i < DiaryBook.size(); i++){
            if(DiaryBook[i]->getDate() < beginDt)
                continue;
            else if(DiaryBook[i]->getDate() > endDt)
                break;
            cout << DiaryBook[i]->getDate() << endl;
            cout << DiaryBook[i]->getTextLine(0) << endl;
        }
    }
    for(i = 0; i < DiaryBook.size(); i++)
        delete DiaryBook[i];
    return 0;
}