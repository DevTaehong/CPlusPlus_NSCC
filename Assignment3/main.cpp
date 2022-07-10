#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <charconv>
#include "Rational.h"
using namespace std;

bool valid(int den)// check if valid
{
    return (den > 0 || den < 0);
}

int main() {
    // Source code: https://www.cplusplus.com/forum/general/115449/

    cout << fixed << showpoint << setprecision(2);  //2 significant figures
    char again = 'y'; //Loop

    cout << "This program performs several arithmetic operations on two rational numbers." << endl;

    while (toupper(again) == 'Y') //run again
    {
        int num, den;
        char slash; //slash
        string f1, f2;
        bool valid1 = true;
        bool valid2 = true;

        while (true)
        {
            cout << "Enter a rational number (a/b): ";
            getline(cin, f1);// get the entire string from the input
            for(int i=0; i<f1.length() ; i++)
            {
                if(isalpha(f1[i]))
                    valid1 = false;
                if(f1[i]=='.')
                    valid1 = false;
            }//end for
            if(!valid1)
            {
                cout << "Input is NOT valid\n";
            }
            else{
                cout << "Input is valid\n"<<endl;
                break;
            }
        }//end while


        istringstream ss(f1);
        ss >> num >> slash >> den;
        ss.eof() && (slash == '/') && valid(den);//Check string


        // change num, den into strings
        stringstream ss3, ss4;
        int num2 = num;
        int den2 = den;

        ss3 << num2;
        string numToString;
        ss3 >> numToString;

        ss4 << den2;
        string denToString;
        ss4 >> denToString;

        Rational x = Rational(num, den);
        Rational stringTest = Rational(numToString, denToString);

        x.reduction(); //reduce user input
        stringTest.reduction();


        while (true)
        {
            cout << "Enter another rational number (a/b): ";
            getline(cin, f2);// get the entire string from the input
            for(int i=0; i<f2.length() ; i++)
            {
                if(isalpha(f2[i]))
                    valid2 = false;
                if(f2[i]=='.')
                    valid2 = false;
            }//end for
            if(!valid2)
            {
                cout << "Input is NOT valid\n";
            }
            else{
                cout << "Input is valid\n"<<endl;
                break;
            }
        }//end while

        istringstream ss1(f2);
        char divisor; //slash
        ss1 >> num >> divisor >> den;

        ss.eof() && (divisor == '/') && valid(den);//Check string

        // change num, den into strings
        stringstream ss5, ss6;
        int num3 = num;
        int den3 = den;
        string numToString2, denToString2;

        ss5 << num3;
        ss5 >> numToString2;

        ss6 << den3;
        ss6 >> denToString2;

        Rational z = Rational(num, den);
        Rational stringTest2 = Rational(numToString2, denToString2);
        z.reduction(); //reduce user input
        stringTest2.reduction();

        cout << "* Test of Constructors and << operator *" << endl;
        cout << "The first rational number that user entered is: ";
        cout << x;

        cout << "\n\nDefault Constructor";
        Rational defaultRational = Rational();
        cout << "\nDefault Constructor result: "<< defaultRational <<endl <<endl;

        cout << "One Argument Constructor" << endl;
        Rational oneArgument = Rational(num);
        cout << "One Argument Constructor result: "<< oneArgument <<endl<<endl;

        cout << "Two Argument Constructor" << endl;
        Rational twoArgument = z;
        cout << "Two Argument Constructor result: "<< z <<endl<<endl;

        cout << "String Constructor" << endl;
        cout << "String Constructor result: "<< stringTest2 <<endl <<endl;

        cout << "\n\n* Test of logical Operators *" << endl;
        cout << "#1 The '==' operator" << endl;
        if(!(x == z))
        {
            cout<< "The 2 rational numbers are not of the same value." << endl;
            cout << "Their values are: ";
            x.printans();
            cout << " and ";
            z.printans();
        } else{
            cout << "The 2 rational numbers are of the same value." << endl;
        }

        cout << "\n\n#2 The '<' , '>' operators" << endl;
        if (x < z){
            x.printans();
            cout << " is less than ";
            z.printans();
        } else{
            x.printans();
            cout << " is greater than ";
            z.printans();
        }

        Rational rat;
        cout << "\n\n\n* Test of Math operators *" << endl ;
        cout << "#1 The + operator Test" << endl;
        x.printans();
        cout << " + ";
        z.printans();
        cout << " = ";
        rat = x + z;
        rat.printans();
        cout << endl;

        cout << "\n#2 The - operator Test" << endl;
        x.printans();
        cout << " - ";
        z.printans();
        cout << " = ";
        rat = x - z;
        rat.printans();
        cout << endl;

        cout << "\n#3 The * operator Test" << endl;
        x.printans();
        cout << " * ";
        z.printans();
        cout << " = ";
        rat = x * z;
        rat.printans();
        cout << endl;

        cout << "\n#4 The / operator Test" << endl;
        x.printans();
        cout << " / ";
        z.printans();
        cout << " = ";

        if(z.getDenominator() != 0)
        {
            rat = x / z;
            rat.printans();
        }
        else
        {
            cout << "ERROR! DIVIDE BY ZERO  =  UNDEFINED!";
        }


        cout << endl << endl;
        cout << "\nRun Again (y/n)? ";//Ask to run again
        cin >> again;
        cout << endl;
        fflush(stdin);
        cin.clear();

    }

    return 0;
}
