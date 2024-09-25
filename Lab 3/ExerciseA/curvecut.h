/*
* File Name: curvecut.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "circle.h"
#include "rectangle.h"
#ifndef curvecut_h
#define curvecut_h

using namespace std;

class Curvecut : public Circle, public Rectangle{
public:
    Curvecut(double x, double y,double side_a, double side_b, double radius, const char* shapeName);
    Curvecut(Curvecut& src);
    double area();
    double perimeter();
    void display();
private:
};

#endif