//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-20
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
  void Mark::clear() {
    m_mark = -1;
  }
  Mark::Mark() : m_mark(0){}
  Mark::Mark(int mark) {
    if (mark < 0 || mark > 100) clear();
    m_mark = mark;
  }

  Mark::operator bool() const {
    if (m_mark < 0 || m_mark > 100) return false;
    return true;
  }

  Mark::operator int() const {
    if (*this) return m_mark;
    return 0;
  }

  Mark::operator double() const {
    double grade = 0.0;
    int score = int(*this);
    if (score >= 0 && score < 50) grade = 0;
    else if (score >= 50 && score < 60) grade = 1.0;
    else if (score >= 60 && score < 70) grade = 2.0;
    else if (score >= 70 && score < 80) grade = 3.0;
    else if (score >= 80 && score <= 100) grade = 4.0;
    return grade;
  }

  Mark::operator char() const {
    char grade = 'X';
    if (!*this) return grade;
    int score = int(*this);
    if (score >= 0 && score < 50) grade = 'F';
    else if (score >= 50 && score < 60) grade = 'D';
    else if (score >= 60 && score < 70) grade = 'C';
    else if (score >= 70 && score < 80) grade = 'B';
    else if (score >= 80 && score <= 100) grade = 'A';
    return grade;
  }

  Mark& Mark::operator+=(int n) {
    if (!*this) return *this;
    m_mark += n;
    if (m_mark < 0 || m_mark > 100) clear();
    return *this;
  }

  Mark& Mark::operator=(int n) {
    m_mark=n;
    if (m_mark < 0 || m_mark > 100) clear();
    return *this;
  }

  int operator+=(int& n, const Mark& y) {
    int sc = int(y);
    if (sc >= 0 && sc <= 100) {
      n += sc;
    }
    return n;
  }
}
