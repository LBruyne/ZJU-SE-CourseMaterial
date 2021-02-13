/*
* name: Student_2
* author: xuanming,Liu
* This program ask you to read scores and names of students, and print out a summary sheet
* each record includes the name of a student with the names and scores of his courses.
* The user can input as many students as possible.
* The result will be output in specified format.
* A student won't choose every available course in general.
* C functions like scanf and printf are not used.
* Latest revised: 2020.03.14          
*/

#ifndef _2_STU_H
#define _2_STU_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX_NAME_LEN 20
#define MAX_COURSE_NUM 10000
#define STAT_NUM 3
#define AVE_ 0
#define MIN_ 1
#define MAX_ 2
#define INF 100000

struct Course{
    string courseName;
    int score;
};

class Student{
private:
    string name;
    int num;
    float average;
    vector<Course> courses;

public:
    vector<Course> getCourses();
    void setGrades(string cN, int cS);
    void calcAverage();
    void printGrades();
    Student(string, int);
};

void printStat(const vector<Student*> stu);
void calcStat(const vector<Student*> stuRecords, float stat[][MAX_COURSE_NUM]);

#endif 

vector<string> courseList; 

int main()
{
    string name, courseName;
    int courseScore, isInList, i;
    int stuCnt = 0;
    vector<Student*> stu;
    name.resize(MAX_NAME_LEN);
    cout << "This is a CLI program that help with Grade Summary." << endl;
    cout << "Follow the tips and finish your work." << endl;
    cout << "Remember that the student name and course name length upperbond is 7 characters." << endl;
    while(true){
        cout << "Input one student's name: " << endl;
        cout << "Input \"0\" to end the input and get summary." << endl;
        cin >> name;
        if(name == "0")
            break;
        Student *stuRecord = new Student(name, ++stuCnt);
        cout << "Now please enter the course name and the grade:" << endl;
        cout << "Input \"0\" to end the input." << endl;
        while(true){
        	cin >> courseName;
        	if(courseName == "0")
        		break;
        	cin >> courseScore;
            stuRecord->setGrades(courseName, courseScore);
            for(i = 0, isInList = false; i < courseList.size(); i++)
                if(courseList[i] == courseName){
                    isInList = true;
                    break;
                }
            if(!isInList)
                courseList.push_back(courseName);        
        }
        stu.push_back(stuRecord);
    }
    // print header
    cout << "no\t" << "name\t";
    for(int i = 0; i < courseList.size(); i++)
        cout << courseList[i] << "\t";
    cout << "average\t" << endl;
    // print student grades
    for(int i = 0; i < stu.size(); i++){
        stu[i]->calcAverage();
        stu[i]->printGrades();
    }
    // pritn statistics
    printStat(stu);
    cout << "Bye!" << endl;
    system("Pause"); 
    return 0;
}

// The following member function belongs to class Student.
Student::Student(string stuName, int stuNum)
{
    name = stuName;
    num = stuNum;
}

vector<Course> Student::getCourses()
{
    return courses;
}

void Student::setGrades(string cN, int cS)
{
    // set one student's grades.
    Course courseRecord;
    courseRecord.courseName = cN;
    courseRecord.score= cS;
    courses.push_back(courseRecord);
}

void Student::calcAverage()
{
    // calculate the average score of one student's courses.
    float sum = 0;
    for(int i = 0; i < courses.size(); i++)
        sum += courses[i].score;
    average = sum / courses.size();
}

void Student::printGrades()
{
    // print line by line of the student's personal grades.
    // choose the courses that he studied.
    // first is his information,
    // followed by its grades.
	int i, j, isStudied;
    cout << num << "\t" << name << "\t";
    for(i = 0; i < courseList.size(); i++){
        for(j = 0, isStudied = 0; j < courses.size(); j++)
            if(courses[j].courseName == courseList[i]){
                cout << courses[j].score << "\t";
                isStudied = 1;
                break;
            }
        if(!isStudied)
            cout << "\t";
    }
    cout << average << endl;
}

void printStat(const vector<Student*> stuRecords)
{
    float stat[STAT_NUM][MAX_COURSE_NUM];
    calcStat(stuRecords, stat);
    // print statistics.
    // simply output them.
    cout << "\t" << "average\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< fixed << setprecision(1) << stat[AVE_][i] << "\t";
    cout << endl;
    cout << "\t" << "min\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< stat[MIN_][i] << "\t";
    cout << endl;
    cout << "\t" << "max\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< stat[MAX_][i] << "\t";
    cout << endl;
}

void calcStat(const vector<Student*> stuRecords, float stat[][MAX_COURSE_NUM])
{
    // For each course,
    // find the person studied it, and calculate
    //  - Average
    //  - Maximum
    //  - Minimum
    vector<Course> stuCourses;
    int cnt;
    for(int i = 0; i < courseList.size(); i++){
        stat[AVE_][i] = 0;
        stat[MAX_][i] = (-(INF));
        stat[MIN_][i] = (INF);
        cnt = 0;
        for(int j = 0; j < stuRecords.size(); j++){
            stuCourses = stuRecords[j]->getCourses();
            for(int k = 0; k < stuCourses.size(); k++){
                if(stuCourses[k].courseName == courseList[i]){
                    // this student j has this course i
                    stat[AVE_][i] += stuCourses[k].score;
                    stat[MAX_][i] = stat[MAX_][i] < stuCourses[k].score ? stuCourses[k].score : stat[MAX_][i];
                    stat[MIN_][i] = stat[MIN_][i] > stuCourses[k].score ? stuCourses[k].score : stat[MIN_][i];
                    cnt ++;
                }
            }
        }
        stat[AVE_][i] /= cnt;
    }
}
