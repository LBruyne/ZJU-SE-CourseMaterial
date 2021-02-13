/*
 * File: Add.cpp
 * Author: Xuanming, Liu
 * Usage: 
 * Here we achieve the pdadd function.
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
    // if not reach the eof flag.
    while(!fileIn.eof()){
        // read one diary.
        // get the date
        getline(fileIn, date);
        Diary* diary = new Diary(date);
        getline(fileIn, text);
        // if not reach the '.'.
        while(text != "."){
            // read one line.
            diary->addLine(text);
            getline(fileIn, text);
        }
        DiaryBook.push_back(diary);
    }
    fileIn.close();

    date = argv[1];
    Diary* diary = new Diary(date);
    cout << "Input your diary here:" << endl;
    getline(cin, text);
    while(text != "."){
        diary->addLine(text);
        getline(cin, text);
    }
    // traversal the vector to see whether the date is existed or not.
    for(i = 0; i < DiaryBook.size() && DiaryBook[i]->getDate() < diary->getDate(); i++);
    if(i == DiaryBook.size())
        // if not:
        DiaryBook.push_back(diary);
    else if(DiaryBook[i]->getDate() == diary->getDate())
        // if existed:
        DiaryBook[i] = diary;
    else
        // the diary is old.
        DiaryBook.insert(DiaryBook.begin()+i, diary);

    // write the data back to file.
    ofstream fileOut(FILE_PATH);
    for(int i = 0; i < DiaryBook.size(); i++){
        fileOut << DiaryBook[i]->getDate() << endl;
        for(int j = 0; j < DiaryBook[i]->getTextSize(); j++)
            fileOut << DiaryBook[i]->getTextLine(j) << endl;
        fileOut << "." << endl;
    }
    fileOut.close();
    
    // delete to maintain the memory.
    for(i = 0; i < DiaryBook.size(); i++)
        delete DiaryBook[i];
    return 0;
}