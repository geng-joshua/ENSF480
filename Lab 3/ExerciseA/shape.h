/*
* File Name: shape.h
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 20, 2024
*/

#ifndef shape_h
#define shape_h
#include "point.h"
#include <cmath>

class Shape {
public:
    Shape(Point origin, const char* shapeName);
    Shape(const Shape& source);
    Shape& operator =(const Shape& rhs);
    virtual ~Shape();
    const Point& getOrigin() const;
    const char* getName() const;
    //Pure virtual function defined
    virtual void display() = 0;
    double distance (Shape& other);
    static double distance (Shape& the_shape, Shape& other);
    void move (double dx, double dy);
    //Pure virtual functions defined
    virtual double perimeter() = 0;
    virtual double area() = 0;
    
protected:
    Point origin;
    char* shapeName;
};
#endif /* shape_h */
