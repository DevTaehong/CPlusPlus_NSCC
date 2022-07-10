//
// Created by Taehong on 2021-11-11.
//

#include <iostream>
#include "Student.h"

using namespace std;

void Student::setName(string name) {
    this->name = name;
}

Student::Student()  //default constructor
{
    cout << "Default Constructor called" << endl;

    this->name = "";
    this->numCourse = 0;
    this->courseList = new string[0];

}

Student::Student(string name, int numCourse, string *courseList) {
    this->name = getName();
    this->numCourse = numCourse;
    this->courseList = courseList;

}

//copy constructor
Student::Student(const Student &obj)
{
    cout<<"Copy Constructor Called"<<endl;
    this->setName(name);
    numCourse = obj.numCourse;
    courseList = obj.courseList;

}

Student::~Student()
{
    numCourse = 0;
    name = "";
    reset();
}

void Student::reset()
{
    if (courseList) {
        delete [] courseList;
        courseList = NULL;
        numCourse = 0;
    }
}

void Student::add()
{
    reset();
    cout << "Enter number of classes > ";
    cin >> numCourse;
    cin.ignore(2,'\n');
    if (numCourse > 0) {
        courseList = new string[numCourse];
        for (int i=0; i<numCourse; i++)
        {
            cout << "Enter name of classes " << (i+1) << " > ";
            getline(cin, courseList[i]);
        }
    }
    cout << endl;
}

void Student::outPut()
{
    cout << "Number of courses: " << numCourse << endl;
    cout << "Class List: " << endl;
    for (int i = 0; i < numCourse; i++)
    {
        cout  << right << i + 1 << ") " << courseList[i] << endl;
    }
}

Student& Student::operator =(const Student& rightSide)
{
    reset();
    cout << "Overloaded Constructor called" << endl;
    numCourse = rightSide.numCourse;
    if (numCourse > 0)
    {
        courseList = new string[numCourse];
        for (int i = 0; i < numCourse; i++)
        {
            courseList[i] = rightSide.courseList[i];
        }
    }
    return *this;
}




