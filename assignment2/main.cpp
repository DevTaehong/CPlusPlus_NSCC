#include <iostream>
#include "Student.h"

int main() {


    Student s1;
    string name;

    cout << "Enter #1's student name: ";
    getline(cin, name);
    s1.setName(name);

    s1.add();
    cout << "Student #1's information:" << endl;
    cout << "Student name: "<< s1.getName() << endl;
    s1.outPut();
    cout << endl;

    Student s2{s1};
    cout << "Enter #2's student name: ";
    getline(cin, name);
    s2.setName(name);

    cout << "Student #2's information after assignment from student #1:" << endl;
    cout << "Student name: "<< s2.getName() << endl;
    s2.outPut();
    s1.reset();
    cout << "\n";
    cout << "Student #1's information after reset:" << endl;
    cout << s1.getName() << endl;
    s1.outPut();

    cout << "Student #2's information: " << endl;
    s2.outPut();
    cout << endl;

    Student s3 = s2;
    cout << "Student #3's information: " << endl;
    s3.outPut();



    return 0;
}