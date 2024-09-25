/*
* File Name: customer.h
* Assignment: Lab 3 Exercise C
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#ifndef CUSTOMER
#define CUSTOMER
#include <iostream>

#include "mystring2.h"

using namespace std;

class Customer{
 friend ostream& operator << (ostream&,  const Customer& c);

 public:
  Customer(const Mystring& fn, const Mystring& ln, const Mystring& ad, const Mystring& ph);
  const char* getFname() const;
  const char* getLname()const;
  const char* getAddress()const;
  const char* getPhone()const;
  void setFname(const char*s);
  void setLname(const char*s);
  void setAddress(const char*s);
  void setPhone(const char*s);

 private:
  Mystring fname;
  Mystring lname;
  Mystring address;
  Mystring phone;
};


#endif
