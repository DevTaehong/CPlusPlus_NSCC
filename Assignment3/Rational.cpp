//
// Created by Taehong on 2021-11-26.
//
#include <iostream>
#include <sstream>
#include "Rational.h"

using namespace std;

Rational::Rational() //Default Constructor
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
}

Rational::Rational(int n)
{
    numerator = n;
    denominator = 1;
}

Rational::Rational(string n, string d)
{
    cout << endl;
    stringNum = n;
    stringDenom = d;

    stringstream ss, ss2;
    ss << stringNum;
    ss >> numerator;

    ss2 << stringDenom;
    ss2 >> denominator;
}

int Rational::Normalization(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Normalization(b, a % b);
    }
}

void Rational::reduction()
{
    int temp = Normalization(numerator, denominator);
    numerator = numerator / temp;
    denominator = denominator / temp;
}

void Rational::Denominator(int d)
{
    denominator = d;
}

void Rational::Numerator(int n)
{
    numerator = n;
}

int Rational::getDenominator()
{
    return denominator;
}

int Rational::getNumerator()
{
    return numerator;
}

void Rational::printans()
{
    if(denominator == 1)
    {
        cout << numerator;
    }
    else if(numerator == 0)
    {
        cout << numerator;
    }
    else //if in form a/b
    {
        cout << numerator << "/" << denominator;
    }
}

Rational& Rational::operator + (Rational& temp)
{
    int Denom = denominator * temp.getDenominator(); //get new denominator
    int Numon = (numerator * temp.getDenominator()) + (denominator * temp.getNumerator()); //calculate new numerator
    Rational back = Rational(Numon, Denom);
    back.reduction(); //reduce answer
    return back;
}

Rational& Rational::operator - (Rational& temp)
{
    int Denom = denominator * temp.getDenominator(); //get new denominator
    int Numon = (numerator * temp.getDenominator()) - (denominator * temp.getNumerator()); //calculate new numerator
    Rational back = Rational(Numon, Denom);
    back.reduction(); //reduce answer
    return back;
}

Rational& Rational::operator * (Rational& temp)
{
    int Denom = denominator * temp.getDenominator(); //get new denominator
    int Numon = numerator * temp.getNumerator(); //calculate new numerator
    Rational back = Rational(Numon, Denom);
    back.reduction(); //reduce answer
    return back;
}

Rational& Rational::operator / (Rational& temp)
{
    int temp1 = temp.getDenominator();
    temp.Denominator(temp.getNumerator());
    temp.Numerator(temp1);
    int Denom = denominator * temp.getDenominator(); //get new denominator
    int Numon = numerator * temp.getNumerator(); //calculate new numerator
    Rational back = Rational(Numon, Denom);
    back.reduction(); //reduce answer
    return back;
}


ostream& operator<< (ostream &output, Rational& num)
{
    output << num.numerator << "/" << num.denominator;
    return output; //returns an ostream obj
}

bool operator == (const Rational& leftSide, const Rational& rightSide){
    int leftnum = leftSide.numerator;
    int leftden = leftSide.denominator;
    int rightnum = rightSide.numerator;
    int rightden = rightSide.denominator;

    if(leftnum == rightnum && leftden == rightden)
        return true;
    else
        return false;

}
bool operator < (const Rational& leftSide, const Rational& rightSide){
    int leftnum = leftSide.numerator;
    int leftden = leftSide.denominator;
    int rightnum = rightSide.numerator;
    int rightden = rightSide.denominator;

    if((leftnum/leftden)<(rightnum/rightden)){
        return true;
    } else return false;
}

bool operator > (const Rational& leftSide, const Rational& rightSide){
    int leftnum = leftSide.numerator;
    int leftden = leftSide.denominator;
    int rightnum = rightSide.numerator;
    int rightden = rightSide.denominator;

    if((leftnum/leftden)>(rightnum/rightden)){
        return true;
    } else return false;
}


