/*
* File Name: rectangle.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#ifndef rectangle_h
#define rectangle_h
#include "square.h"

class Rectangle : public virtual Square {
public:
    Rectangle(double x, double y, double side_a, double side_b, const char* shapeName);
    Rectangle(const Rectangle& source);
    Rectangle& operator =(const Rectangle& rhs);
    ~Rectangle();
    double get_side_b();
    void set_side_b(double side_b);
    void set_side_a(double side_a);
    double area() override;
    double perimeter() override;
    void display() override;
protected:
    double side_b;
};

#endif /* rectangle_h */
