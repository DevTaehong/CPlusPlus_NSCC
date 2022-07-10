//
// Created by Taehong on 2021-11-11.
//

#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H

#include <string>

using namespace std;

class Student
{
    private:
        string name;
        int numCourse;
        string *courseList;

    public:
        Student();//default constructor
        Student(string name, int numCourse, string *courseList);
        Student(const Student &obj); //copy constructor
        ~Student();//virtual destructor

        Student& operator = (const Student& rightSide);

        void setName(string name);

        string getName() const
        {
            return name;
        }

        void add();
        void outPut();
        void reset();


};


#endif //ASSIGNMENT2_STUDENT_H
