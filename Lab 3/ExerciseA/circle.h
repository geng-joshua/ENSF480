/*
* File Name: circle.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "shape.h"
using namespace std;
#ifndef circle_h
#define circle_h

class Circle : public virtual Shape{
public:
    Circle(double radius, double x, double y, const char* shapeName);
    Circle(const Circle& src);
    //Circle& is used to prevent copies of object. Instead, it just changes the referenced object when called.
    Circle& operator=(const Circle& src);
    double area() override;
    double perimeter() override;
    double get() const;
    void set(double radius);
    void display() override;
protected:
    double radius;
};


#endif