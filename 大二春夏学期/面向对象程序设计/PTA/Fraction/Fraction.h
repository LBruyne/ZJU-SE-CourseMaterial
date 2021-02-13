#ifndef FRAC_H
#define FRAC_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Fraction{
private:
    int numer;
    int denomi;
    int flag, isValid;
    int gcdFraction();
    void reduce();

public:
    // ctor & dtor
    Fraction():numer(0),denomi(1){
        cout << "Default ctor is built! " ;
    }
    Fraction(int n):numer(n),denomi(1){
        reduce();
    }
    Fraction(int n, int d):numer(n),denomi(d){ 
        reduce();
    }
    Fraction( const Fraction& obj):numer(obj.numer),denomi(obj.denomi){
        reduce();
    }
    // conversion from a finite decimal string like: 1.414
    Fraction(double n){
		string s = to_string(n);
        int len = s.size();
		int dot = s.find(".");
        if(dot == s.npos)
            dot = -1;
        s.erase(dot, dot);
        numer = n * pow(10, len-dot-1);
        denomi = pow(10, len-dot-1);
		reduce();
	}
    // arithmetic
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
    // relation
    bool operator>(const Fraction& b);
	bool operator<(const Fraction& b);
    bool operator<=(const Fraction& b);
    bool operator>=(const Fraction& b);
	bool operator==(const Fraction& b);
	bool operator!=(const Fraction& b);
    // type cast
    operator double() const{
        return double(numer) / double(denomi);
    }
    operator string() const{
        double d = double(numer) / double(denomi);
        string s = to_string(d);
        return s;
    }
    // i/o
    friend istream& operator>> (istream& is, Fraction& f){
        char c;
        is >> f.numer >> c >> f.denomi;
        if(c != '/'){
            cout << "Not a legal input" << endl;
            system("PAUSE");
            exit(0);
        }
        return is;
    }
    friend ostream& operator<< (ostream& os, Fraction& f){
        // deal with some special problem.
        if(f.numer == f.denomi)
            os << "1";
        else if(f.numer == 0)
            os << "0";
        else if(f.denomi == 1)
            os << f.numer;
        else
            os << f.numer << '/' << f.denomi;  
        return os; 
    }
};

#endif
