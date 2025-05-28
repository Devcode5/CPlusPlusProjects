//
//  courseGrade.cpp
//  StructuredData
//
//  Created by Aqila Nasiry on 4/30/25.
//

//#include <stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

struct Student {
    string name;
    string idNum;
    float *tests; //pointer to an array of test scores
    float average;
    char grade;
    
};

//Functions declaration
void studentInfo(Student* students, int studentNumber , int testNumber);
void calcGrade(Student* students, int studentNumber, int testNumber);
void displayData(Student* students, int studentNumber);
void clear(Student* students, int studentNumber);

int main(){
    int studentNumber;
    int testNumber;
    
    do{
        cout << "How many students?";
        cin >> studentNumber;
    }while(studentNumber <=0);
    
    do {
        cout << "How many tests the students took?";
        cin >> testNumber;
        //input validation: making sure that the user enters positive numbers.
    }while(testNumber<=0);
    
    /* dynamically allocate an array of structures. Each structure’s Tests member should point to a dynamically allocated array that will hold the test scores
    
    */
    Student *students = new Student[studentNumber];
    studentInfo(students, studentNumber, testNumber);
    calcGrade(students, studentNumber, testNumber);
    displayData(students, studentNumber);
        clear(students, studentNumber);
    
    //functions call
    return 0;
}


void studentInfo(Student *students, int studentNumber, int testNumber){
    for (int i = 0; i < studentNumber; i++) {
            cin.ignore();
            cout << "\nEnter name of student " << (i + 1) << ": ";
            getline(cin, students[i].name);

            cout << "Enter ID number: ";
            getline(cin, students[i].idNum);

            // Allocate memory for test scores
            students[i].tests = new float[testNumber];

            for (int j = 0; j < testNumber; j++) {
                float score;
                do {
                    cout << "Enter score for test #" << (j + 1) << ": ";
                    cin >> score;
                } while (score < 0);
                *(students[i].tests + j) = score;
            }
        }
    }
void calcGrade(Student* students, int studentNumber, int testNumber) {
    for (int i = 0; i < studentNumber; i++) {
        float total = 0;

        for (int j = 0; j < testNumber; j++) {
            total += *(students[i].tests + j);
        }

        students[i].average = total / testNumber;

        float avgerage = students[i].average;

        if (avgerage >= 90)
            students[i].grade = 'A';
        else if (avgerage >= 80)
            students[i].grade = 'B';
        else if (avgerage >= 70)
            students[i].grade = 'C';
        else if (avgerage >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

void displayData(Student* students, int studentNumber) {
//    cout << "\n-----------------------------------------------------------------\n";
    cout << "Name     ID Number     Average        Grade\n";
    cout << "-------------------------------------------\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < studentNumber; i++) {
        cout << left << setw(18) << students[i].name
             << setw(13) << students[i].idNum
             << setw(9) << students[i].average
             << students[i].grade << endl;
    }
}

/*
 following function is responsible for releasing the memory that was dynamically allocated during the program.
 */

void clear(Student *students, int studentNumber){
    for (int i = 0; i < studentNumber; i++) {
            delete[] students[i].tests; // free each student's test score array
        }
    //using delete we can free the array of student struct
        delete[] students;

}


