/*
* File Name: square.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#ifndef square_h
#define square_h
#include "shape.h"
#include <cmath>

class Square : public virtual Shape {
public:
    Square(double x, double y, double side_a, const char* shapeName);
    Square(const Square& source);
    Square& operator =(const Square& rhs);
    ~Square();
    double getside_a();
    void setside_a(double side_a);
    double area() const;
    double perimeter() const;
    void display() override;
    double perimeter() override;
    double area() override;
protected:
    double side_a;
};

#endif /* square_h */
