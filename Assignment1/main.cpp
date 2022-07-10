#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void customString(ifstream& inStream, ofstream& outStream);

struct MyException : public exception
{
public:
    const string what()
    {
        return "Input file failed to open.";
    }
};//end struct


int main() {
    ifstream fin;
    ofstream fout;
    char fileName[100];
    char convertedFileName[100];
    char bad_chars[] = "!@%^*~|:/<>";
    char invalid_found = false;


    cout<<"Begin editing files."<<endl<<endl;


    cout << "Enter the CPP file name with the extension: (ex, FileName.cpp) ";
    cin >> fileName;
    for (int i = 0; i < strlen(bad_chars); ++i){ // Source: https://stackoverflow.com/questions/10159230/validating-user-input-for-filenames
        if (strchr(fileName, bad_chars[i]) != NULL){
            invalid_found = true;
            break;
        }//end  if
    }//end for
    if (invalid_found){
        cout << "You cannot use these symbols in your file name => !@%^*~|:/<> "<<endl;
        exit(1);
    }//end if
    fin.open(fileName);
    try {
        if (!fin.is_open()){
            throw MyException();
        }//end if
    }//end try
    catch (MyException& e){
        cout<<e.what()<<endl;
        exit(1);
    }



    cout << "Enter the html file name with the extension: (ex, FileName.html) ";
    cin >> convertedFileName;
    for (int i = 0; i < strlen(bad_chars); ++i)
    {
        if (strchr(convertedFileName, bad_chars[i]) != NULL){
            invalid_found= true;
            break;
        }//end if
    }//end for
    if (invalid_found){
        cout <<"You cannot use these symbols in your file name => !@%^*~|:/<>"<<endl;
        exit(1);
    }//end if
    fout.open(convertedFileName);
    try {
        if (!fout.is_open()){
            throw invalid_argument("Output file failed to open.");
        }//end if
    }
    catch (invalid_argument& e){
        cout<<e.what()<<endl;
        exit(1);
    }//end catch


    try {
        fout << "<PRE>"<< endl;
    }
    catch (...){
        cout<<"There's an error.";
    }

    customString(fin, fout);

    try {
        fout << "</PRE>"<< endl;
    }
    catch (...){
        cout<<"There's an error.";
    }

    try {
        fin.close();
        fout.close();
    }
    catch (...){
        cout<<"There's an error.";
    }

    cout<<"End file converting"<<endl<<endl;
    return 0;
}

void customString(ifstream& inStream, ofstream& outStream)
{
    char letter;

    try {
        inStream.get(letter);
    }
    catch (...){
        cout<<"File read fails.";
    }

    try {
        while (!inStream.eof())
        {
            if (letter == '<'){
                outStream << "&lt;";
            }
            else if (letter == '>'){
                outStream << "&gt;";
            }
            else{
                outStream << letter;
            }
            inStream.get(letter);
        }//end while
    }//end try
    catch (...){
        cout<<"File write fails.";
    }
}//end customString


