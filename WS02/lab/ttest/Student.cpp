/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/01/20
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students = nullptr;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

      bool load(Student &students) {
      bool ok = false;
      char name[128];
      if (read(name)) {
          students.m_name = new char[strlen(name) + 1];
          strcpy(students.m_name, name);
          read(students.m_studentNumber);
          read(students.m_gpa);
          ok = true;
      }
      return ok;
   }
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfStudents = noOfRecords();
          students = new Student[noOfStudents];
          for(i=0;i<noOfStudents;i++)
          {
              load(students[i]);
          }
         if (i != noOfStudents){
             cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }
void display(Student& students)
{
    cout << students.m_name << ", " << students.m_studentNumber << ": " << students.m_gpa << endl;
}

void display(void)
{
    int i,j;
    sort();
    for(i=0,j=1;i<noOfStudents;i++)
    {
        cout << j++ << ": ";
        display(students[i]);
    }
}

void deallocateMemory(void)
{
    int i;
    for(i=0;i<noOfStudents;i++)
    {
        delete [] students[i].m_name;
        students[i].m_name = nullptr;
    }
    delete[] students;
    students = nullptr;
}
}
