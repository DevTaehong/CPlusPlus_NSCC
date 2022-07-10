//
// Created by Taehong on 2021-11-26.
//

#ifndef ASSIGNMENT3_RATIONAL_H
#define ASSIGNMENT3_RATIONAL_H
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;
    string stringNum;
    string stringDenom;
    int Normalization(int, int); //Determine the GCD

public:
    Rational();
    Rational(int);
    Rational(int, int);
    Rational(string, string);

    int getNumerator();
    int getDenominator();

    void reduction();
    void Numerator(int);
    void Denominator(int);
    void printans();

    Rational& operator + ( Rational& rightSide);
    Rational& operator - ( Rational& rightSide);
    Rational& operator / ( Rational& rightSide);
    Rational& operator * ( Rational& rightSide);

    friend ostream& operator<<(ostream &output, Rational &num);

    friend bool operator == (const Rational& leftSide, const Rational& rightSide);
    friend bool operator < (const Rational& leftSide, const Rational& rightSide);
    friend bool operator > (const Rational& leftSide, const Rational& rightSide);
};

#endif //ASSIGNMENT3_RATIONAL_H
