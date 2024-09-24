// ENSF 480  - Lab 3, Ex C
// M. Moussavi

#include "customer.h"
#include <iostream>

using namespace std;

Customer::Customer(const Mystring& fn, const Mystring& ln, const Mystring& ad, const Mystring& ph):fname(fn), lname(ln), address(ad), phone(ph)
{
}

const char* Customer::getFname()const
{
  return fname.c_str();
}

const char* Customer::getLname()const
{
  return lname.c_str();
}

const char* Customer::getAddress()const
{
  return address.c_str();
}

const char* Customer::getPhone()const
{
  return phone.c_str();
}

void Customer::setFname(const char*s)
{
  Mystring tmp(s);
  fname=tmp;
}

void Customer::setLname(const char*s)
{
  Mystring tmp(s);
  lname=tmp;
}

void Customer::setAddress(const char*s)
{
  Mystring tmp(s);
  address=tmp;
}

void Customer::setPhone(const char*s)
{
  Mystring tmp(s);
  phone=tmp;
}


ostream& operator << (ostream& os, const Customer& c)
{
  os<< "Nmae: "<< c.getFname();
  os<<" " <<c.getLname();
  os<< ". Address: " << c.getAddress();
  os<< ". Phone:: " << c.getPhone();
  return os;
}
