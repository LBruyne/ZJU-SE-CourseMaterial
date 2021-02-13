/*
* This program ask you to input 10 records in the console,
* each record includes the name of a student and the scores of his three courses.
* The result will be output in specified format.
* C functions like scanf and printf are not used.
* Latest revised: 2020.03.04             
*/

#ifndef _Stu_h_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define STU_NUM 10
#define COURSE_NUM 3
#define MAX_NAME_LENGTH 20
#define INF 10000

struct Record;
typedef struct Record *gradeRecords;

gradeRecords readRecords();
void processGrades( gradeRecords records, float averageScore[], int minScore[], int maxScore[] );
void printGradeLists( gradeRecords records, float averageScore[], int minScore[], int maxScore[] );
void processAverage( gradeRecords records, float averageScore[] );
void processMaximum( gradeRecords records, int maxScore[] );
void processMinimum( gradeRecords records, int minScore[] );
float calcAverage( int grade[] );
void printFloatStatistic( string statisticHeader, float statistic[] );
void printIntStatistic( string statisticHeader, int statistic[] );

#endif

struct Record{
    int regisNum;
    // char name[MAX_NAME_LENGTH];
    string name;
    int courseGrade[COURSE_NUM]; 
    float average;
};

int main()
{
    float averageOfGrade[COURSE_NUM] = {0};
    int minOfGrade[COURSE_NUM] = {0};
    int maxOfGrade[COURSE_NUM] = {0};
    gradeRecords records = readRecords();
    processGrades(records, averageOfGrade, minOfGrade, maxOfGrade);
    printGradeLists(records, averageOfGrade, minOfGrade, maxOfGrade);
    return 0;
}

gradeRecords readRecords()
{
    // read the ten records from console.
    // gradeRecords records = (gradeRecords)malloc(sizeof(struct Record) * STU_NUM);
    gradeRecords records = new Record[STU_NUM];
    for(int i = 0; i < STU_NUM; i++){
        cin >> records[i].name;
        for(int j = 0; j < COURSE_NUM; j++)
            cin >> records[i].courseGrade[j];
        records[i].regisNum = (i + 1);
        // calculate the average score of a student
        records[i].average = calcAverage(records[i].courseGrade);
    }
    return records;
}

void processGrades( gradeRecords records, float averageScore[], int minScore[], int maxScore[] )
{
    // calculate thr average score, max score and min score of each course.
    // divide the program into 3 functions.
    // In each function, we traversal the data and calculate each number,
    processAverage(records, averageScore);
    processMaximum(records, maxScore);
    processMinimum(records, minScore);
}

void printGradeLists( gradeRecords records, float averageScore[], int minScore[], int maxScore[] )
{
    // print the table header
    cout << "no\t" << "name\t" << "score1\t" << "score2\t" << "score3\t" << "average\t" << endl;
    for(int i = 0; i < STU_NUM; i++){
        cout << records[i].regisNum << "\t";
        cout << records[i].name << "\t";
        for(int j = 0; j < COURSE_NUM; j++)
            cout << records[i].courseGrade[j] << "\t";
        cout << records[i].average << "\t" << endl;
    }
    // print the average, min and max score of each course
    // The statistics are different value type, so we use specified function to process them.
    printFloatStatistic("average", averageScore);
    printIntStatistic("min", minScore);
    printIntStatistic("max", maxScore);
}

void processAverage( gradeRecords records, float averageScore[] )
{
    // Sum the score of each course, and divide the sum by STU_NUM.
    for(int i = 0; i < COURSE_NUM; i++){
        for(int j = 0; j < STU_NUM; j++)
            averageScore[i] += records[j].courseGrade[i];
        averageScore[i] /= STU_NUM;
    }
}

void processMaximum( gradeRecords records, int maxScore[] )
{
    for(int i = 0; i < COURSE_NUM; i++){
        int max = -INF;
        for(int j = 0; j < STU_NUM; j++)
            max = records[j].courseGrade[i] > max ? records[j].courseGrade[i] : max;
        maxScore[i] = max;
    }
}

void processMinimum( gradeRecords records, int minScore[] )
{
    for(int i = 0; i < COURSE_NUM; i++){
        int min = INF;
        for(int j = 0; j < STU_NUM; j++)
            min = records[j].courseGrade[i] < min ? records[j].courseGrade[i] : min;
        minScore[i] = min;
    }
}

float calcAverage( int grade[] )
{
    // this is a utility function to calculate the average of a array of data.
    float sumOfGrade = 0;
    for(int i = 0; i < COURSE_NUM; i++)
        sumOfGrade += grade[i];
    return sumOfGrade / COURSE_NUM;
}

void printFloatStatistic( string statisticHeader, float statistic[] )
{
    // print the average score.
    // Since the score is a float var, we should fix its precision.
    cout << "\t" << statisticHeader;
    for(int i = 0; i < COURSE_NUM; i++)
        cout << "\t" << fixed << setprecision(1) << statistic[i];
    cout << endl;
}

void printIntStatistic( string statisticHeader, int statistic[] )
{
    // Just simply output the formated statistics.
    cout << "\t" << statisticHeader;
    for(int i = 0; i < COURSE_NUM; i++)
        cout << "\t" << statistic[i];
    cout << endl;
}
