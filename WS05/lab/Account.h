//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-18
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance;
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account &operator=(int input);
      Account &operator=(Account& account);
      Account &operator+=(double balance);
      Account &operator-=(double balance);
      Account &operator<<(Account& account);
      Account &operator>>(Account& account);
      friend double operator+(const Account& left, const Account& right);
      friend double operator+=(double& balance, const Account& account);
   };


}
#endif // SDDS_ACCOUNT_H_
