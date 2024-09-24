/*
* File Name: rectangle.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 20, 2024
*/

#include "rectangle.h"
#include <string.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* shapeName)
    : Shape(Point(x, y), shapeName), Square(x, y, side_a, shapeName), side_b(side_b) {
         if (side_b <= 0) {
            throw invalid_argument("Error: Side length must be positive.");
        }
        this->side_b = side_b;
    }

Rectangle::Rectangle(const Rectangle& source) 
    : Shape(source),
    Square(source), //Calls the copy constructor of the base class Square to initialize the base class members
    side_b(source.side_b) {} // Copies the side_b member from the other object into the new object.



Rectangle& Rectangle::operator =(const Rectangle& rhs){
    if (this == &rhs){
        return *this;
    }
    Square::operator=(rhs); // Call the base class assignment operator to copy base class members
    this->side_b = rhs.side_b;
    return *this;
}

Rectangle::~Rectangle(){
    // Nothing dynamically allocated, use default destructor
}

double Rectangle::get_side_b(){
    return this->side_b;
}

void Rectangle::set_side_b(double side_b){
    this->side_b = side_b;
}
void Rectangle::set_side_a(double side_a){
    this->side_a = side_a;
}

double Rectangle::area() {
    return side_a * side_b;
}

double Rectangle::perimeter() {
    return (2 * side_a + 2 * side_b);
}

void Rectangle::display(){
    cout << "\nRectangle Name: " << shapeName << endl;
    this->origin.display();
    cout << "Side a: " <<this->side_a << endl;
    cout << "Side b: " <<this->side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}