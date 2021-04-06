/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/01/20
*/
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "students.csv"
namespace sdds {
   struct Student {
      char* m_name;
      int m_studentNumber;
      double m_gpa;
   };
   void sort();
   bool load(Student& students);
   bool load();
void display(Student& students);
void display(void);
void deallocateMemory(void);
}
#endif
