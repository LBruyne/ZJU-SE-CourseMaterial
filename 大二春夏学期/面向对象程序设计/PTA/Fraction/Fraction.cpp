#include "Fraction.h"
using namespace std;

int Fraction::gcdFraction()
{
	// using 2 number to get the greatest common divisor.
	// first check the flag for number 2.
    int a = denomi, b = numer;
	if(b < 0)
		b = -b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

void Fraction::reduce(){
	// reduce the number to the simplest statue.
	// check the flag to see if the numbers are valid.
	// check the flag to  compromise the second number is positive.
	isValid = 1;
	if(denomi == 0)
		isValid = 0;
	else if(numer == 0){
		flag = 1;
		isValid = 0;
	}
	else if(numer < 0 && denomi < 0){
		flag = 1;
		numer = -numer;
		denomi = -denomi;
	}
	else if(numer > 0 && denomi < 0){
		flag = -1;
		denomi = -denomi;
		numer = -numer;
	}
	else if(numer < 0 && denomi > 0){
		flag = -1;
	}
	if(!isValid){
		cout << "There is a fraction using 0 as the denomeinter" << endl;
		system("PAUSE");
		exit(0);
	}
	int greatestCommonDivisor = gcdFraction();
    if(greatestCommonDivisor > 1){
        numer /= greatestCommonDivisor;
        denomi /= greatestCommonDivisor;
    }
}

// Some reload for arithmetic operators.
Fraction Fraction::operator+(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	int d = (this->denomi) * (b.denomi);
	Fraction res(n1+n2, d);
	res.reduce();
	return res;
}

Fraction Fraction::operator-(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	int d = (this->denomi) * (b.denomi);
	Fraction res(n1-n2, d);
	res.reduce();
	return res;
}
Fraction Fraction::operator*(const Fraction& b){
	int n = (this->numer)*(b.numer);
	int d = (this->denomi)*(b.denomi);
	Fraction res(n, d);
	res.reduce();
	return res;
}

Fraction Fraction::operator/(const Fraction& b){
	if(b.flag == 0){
		cout << "The division using a 0 as divider" << endl;
		system("PAUSE");
		exit(0);
	}
	return (*this) * (Fraction(b.denomi, b.numer));
}

// Some reload for relation operators.
bool Fraction::operator<(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	if(n1 < n2)
		return true;
	return false;
}

bool Fraction::operator<=(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	if(n1 <= n2)
		return true;
	return false;
}

bool Fraction::operator>(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	if(n1 > n2)
		return true;
	return false;
}

bool Fraction::operator>=(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	if(n1 >= n2)
		return true;
	return false;
}

bool Fraction::operator==(const Fraction& b){
	int n1 = (this->numer) * (b.denomi);
	int n2 = (this->denomi) * (b.numer);
	if(n1 == n2)
		return true;
	return false;
}

bool Fraction::operator!=(const Fraction& b){
	return !(*this == b);
}
