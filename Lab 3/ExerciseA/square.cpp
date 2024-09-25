/*
* File Name: square.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "square.h"
#include <string.h>
#include <iostream>
using namespace std;

Square::Square(double x, double y, double side_a, const char* shapeName)
        : Shape(Point(x, y), shapeName), side_a(side_a) {
        if (side_a <= 0) {
            throw invalid_argument("Error: Side length must be positive.");
        }
        this->side_a = side_a; // set side_a data member to argument passed as side_a through constructor
}

Square::Square(const Square& source) 
    : Shape(source), //Calls the copy constructor of the base class Shape to initialize the base class members (like origin and shapeName)
      side_a(source.side_a) { // Copies the side_a member from the other object into the new object.

}

Square& Square::operator =(const Square& rhs){
    if (this == &rhs){
        return *this;
    }
    Shape::operator=(rhs); // Call the base class assignment operator to copy base class members
    this->side_a = rhs.side_a;
    return *this;
}

Square::~Square(){
    // Nothing dynamically allocated, use default destructor
}

double Square::getside_a(){
    return this->side_a;
}

void Square::setside_a(double side_a){
    this->side_a = side_a;
}

double Square::area() const{
    return side_a * side_a;
}

double Square::perimeter() const{
    return 4 * side_a;
}

void Square::display() {
    cout << "Square Name: " << shapeName << endl;
    this->origin.display();
    cout << "Side a: " <<this->side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

double Square::perimeter(){
    return this->side_a * 4;
}

double Square::area(){
    return this->side_a * side_a;
}
