/*
 * File: Remove.cpp
 * Author: Xuanming, Liu
 * Usage: 
 * Here we achieve the pdremove function.
 * Latest revised: 2020.04.13             
**/

#include "Diary.h"
using namespace std;

int main(int argc, char* argv[])
{
    ifstream fileIn(FILE_PATH);
    string date, text;
    vector<Diary*> DiaryBook;
    int i;

    // Similar to the others.
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

    // There are must be 2 arguments with 1 parameter.
    if(argc == 2){
        date = argv[1];
        // To find whether the date is existed.
        for(i = 0; i < DiaryBook.size(); i++)
            if(DiaryBook[i]->getDate() == date)
                break;
        // if not.
        if(i == DiaryBook.size()){
             cout << "0" << endl;
             return 0;
        }
        // if existed, delete it.
        if(i != DiaryBook.size()){
            // Delete.
            DiaryBook.erase(DiaryBook.begin()+i, DiaryBook.begin()+i+1);
            ofstream fileOut(FILE_PATH);
            for(int i = 0; i < DiaryBook.size(); i++){
                fileOut << DiaryBook[i]->getDate() << endl;
                for(int j = 0; j < DiaryBook[i]->getTextSize(); j++)
                    fileOut << DiaryBook[i]->getTextLine(j) << endl;
                fileOut << "." << endl;
            }
            fileOut.close();
            cout << "1" << endl;
        }
    }
    else cout << "0" << endl;
    return 0;
}