/*
* File Name: curvecut.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "curvecut.h"
#include <assert.h>

Curvecut::Curvecut(double x, double y,double side_a, double side_b, double radius, const char* shapeName)
    : Shape(Point(x, y), shapeName),
    Square(x, y, side_a, shapeName),
    Rectangle(x, y, side_a, side_b, shapeName),
    Circle(radius, x, y, shapeName){}

Curvecut::Curvecut(Curvecut& src) 
    : Shape(src),
    Square(src),
    Rectangle(src),
    Circle(src){}

double Curvecut::area(){
    return (2 * 3.14159 * radius) / 2;
}

double Curvecut::perimeter(){
    return ((3.14159 * radius) / 2) + 2 * radius;
}

void Curvecut::display(){
    cout << "Curvecut Name: " << shapeName << endl;
    cout << "X-coordinate: " << origin.getx() << endl;
    cout << "Y-coordinate: " << origin.gety() << endl;
    cout << "Width: " << side_a << endl;
    cout << "Length: " << side_b << endl;
    if(side_a < side_b){
        assert(radius<=side_a);
        cout << "Radius of the cut: " << radius << endl;
    }
    else if (side_a > side_b){
        assert(radius<= side_b);
        cout << "Radius of the cut: " << radius << endl;
    }
    else{
        cout << "Error: Radius is less than the smaller width or length" << endl;
    }

    cout << "Radius of the cut: " << radius << endl;
}