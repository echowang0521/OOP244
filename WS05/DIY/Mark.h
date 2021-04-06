//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-20
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
  class Mark {
      int m_mark;
      void clear();
  public:
      Mark();
      Mark(int mark);
      operator int() const;
      operator double() const;
      operator char() const;
      operator bool() const;
      Mark& operator+=(int n);
      Mark& operator=(int n);
  };
  int operator+=(int& n, const Mark& y);
}
#endif
