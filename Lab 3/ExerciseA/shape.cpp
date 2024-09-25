/*
* File Name: shape.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "shape.h"
#include <string.h>
#include <iostream>
using namespace std;

Shape::Shape(Point origin, const char* shapeName): origin(origin)
{
    this->shapeName = new char[strlen(shapeName) + 1];
    strcpy(this->shapeName, shapeName);
}

Shape::Shape(const Shape& source)
    : origin(source.origin) 
    {
    //deep copy shapeName
    if (source.shapeName) {
        this->shapeName = new char[strlen(source.shapeName) + 1];
        strcpy(this->shapeName, source.shapeName);
    } else {
        this->shapeName = nullptr;
    }
}

Shape& Shape::operator =(const Shape& rhs){
    if (this == &rhs) {
            return *this; // Self-assignment check
        }

    // Free existing shapeName memory
    delete[] this->shapeName;

    // Copy shapeName
    if (rhs.shapeName) {
        this->shapeName = new char[strlen(rhs.shapeName) + 1];
        strcpy(this->shapeName, rhs.shapeName);
    } else {
        this->shapeName = nullptr;
    }

    // Copy origin
    this->origin = rhs.origin;

    return *this;
}

Shape::~Shape(){
    // delete this->origin;
    delete[] this->shapeName;
}

const Point& Shape::getOrigin() const{
   return this->origin;
}

const char* Shape::getName() const{
    return this->shapeName;
}

void Shape::display(){
    // char shapeName = *this->shapeName;
    // double x = this->origin.getx();
    // double y = this->origin.gety();
    
    cout << "Shape Name: " << *this->shapeName << endl;
    this->origin.display();
}

double Shape::distance(Shape& other){
    double dx = this->origin.getx() - other.origin.getx();
    double dy = this->origin.gety() - other.origin.gety();
    return sqrt(pow(dx,2)+pow(dy,2));
}

double Shape::distance(Shape& the_shape, Shape& other){
    double dx = the_shape.origin.getx() - other.origin.getx();
    double dy = the_shape.origin.gety() - other.origin.gety();
    return sqrt(pow(dx,2)+pow(dy,2));
}

void Shape::move(double dx, double dy){
    double newx = this->origin.getx() + dx;
    double newy = this->origin.gety() + dy;
    this->origin.setx(newx);
    this->origin.sety(newy);
}