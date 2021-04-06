//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-18
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const{
     if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) {
       return true;
     }
     return false;
   }

   Account::operator int() const {
     return m_number;
   }

   Account::operator double() const{
     return m_balance;
   }

   bool Account::operator~() const{
     if (m_number == 0) return true;
     return false;
   }

   Account& Account::operator=(int input) {
     if (m_number == 0) {
       if (input >= 10000 && input <= 99999) {
         m_number = input;
       } else {
         setEmpty();
       }
     }
     return *this;
   }

   Account& Account::operator=(Account& account) {
     if (m_number == 0 &&
       &account != this &&
       account.m_number >= 10000 &&
       account.m_number <= 99999 &&
       account.m_balance >= 0) {
       m_number = account.m_number;
       m_balance = account.m_balance;

       account.m_number = 0;
       account.m_balance = 0;
     }
     return *this;
   }

   Account& Account::operator+=(double balance) {
     if (m_number >= 10000 &&
     m_number <= 99999 &&
     m_balance >= 0 &&
       balance >= 0) {
       m_balance += balance;
     }
     return *this;
   }

   Account& Account::operator-=(double balance) {
     if (m_number >= 10000 &&
       m_number <= 99999 &&
       m_balance >= 0 &&
       m_balance >= balance &&
       balance >= 0) {
       m_balance -= balance;
     }
     return *this;
   }

   Account& Account::operator<<(Account& account) {
     if (&account != this &&
         m_number >= 10000 &&
         m_number <= 99999 &&
         m_balance >= 0 &&
         account.m_balance >= 0) {
           m_balance += account.m_balance;
           account.m_balance = 0;
         }
         return *this;
   }

   Account& Account::operator>>(Account& account) {
     if (&account != this &&
         m_number >= 10000 &&
         m_number <= 99999 &&
         m_balance >= 0 &&
         account.m_balance >= 0) {
           account.m_balance += m_balance;
           m_balance = 0;
         }
         return *this;
   }

   double operator+(const Account&left, const Account&right) {
     if (left.m_number >= 10000 &&
          left.m_number <= 99999 &&
          left.m_balance >= 0 &&
          right.m_number >= 10000 &&
          right.m_number <= 99999 &&
          right.m_balance >= 0) {
            return left.m_balance + right.m_balance;
          }
          return 0;
   }

   double operator+=(double& balance, const Account& account) {
     if (account.m_number >= 10000 &&
          account.m_number <= 99999 &&
          account.m_balance >= 0) {
            balance += account.m_balance;
          }
      return balance;
   }
}
