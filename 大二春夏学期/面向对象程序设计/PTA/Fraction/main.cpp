/*
 * name:  Fraction
 * author: xuanming, Liu
 * latest revise: 2020.05.01
 * Write a class that represents a fraction number like 2/3.
 * Functions below have to be implemented for this class:
 * - default ctor
 * - ctor takes two integers as parameters
 * - copy ctor
 * - arithmetical operators: + - * /
 * - relational operators: < <= == != >= >
 * - type cast to double
 * - to string
 * - inserter and extractor for streams
 * - conversion from a finite decimal string like: 1.414
**/

#include "Fraction.h"
using namespace std;

int main()
{
    int result;
    Fraction fa(12);
    Fraction fb(1, 3);
    Fraction fc(1.414);
    double d = fb;
    string s = fb;
    Fraction fd(fb);
    // output some results for 1,2,3,6,7,9
    cout << "type cast convert to double like 1/3: " << d << endl;
    cout << "type cast convert to string like 1/3: " << s << endl;
    cout << "ctor default: " << Fraction() << endl;
    cout << "ctor takes one integers as parameters like 12: " << fa << endl;
    cout << "ctor takes two integers as parameters like 1, 3: " << fb << endl;
    cout << "ctor as copying: " << fd << endl;
    cout << "conversion from a finite decimal string like 1.414: " << fc << endl;
    cout << endl << "Please input two number using the format a/b: ";

    // user input 2 fraction and output the results.
    cin >> fa >> fb;
    fc = (fa + fb);
    cout << "The sum is: " << fc << endl;
    fc = (fa - fb);
    cout << "The diff is: " << fc << endl;
    fc = (fa / fb);
    cout << "The division is: " << fc << endl;
    fc = (fa * fb);
    cout << "The product is: " << fc << endl;
    result = (fa < fb);
    cout << "The result of < is: " << result << endl;
    result = (fa <= fb);
    cout << "The result of <= is: " << result << endl;
    result = (fa > fb);
    cout << "The result of > is: " << result << endl;
    result = (fa >= fb);
    cout << "The result of >= is: " << result << endl;
    result = (fa != fb);
    cout << "The result of != is: " << result << endl;
    result = (fa == fb);
    cout << "The result of == is: " << result << endl;
    system("PAUSE");
}