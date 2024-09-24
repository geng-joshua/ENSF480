#include "circle.h"
// #define int PI = 3.14159

//In constrcutor of derived class, must define all variables in parameter before calling other class constructors.
Circle::Circle(double radius, double x, double y, const char* shapeName) 
    : Shape(Point(x, y), shapeName),
    radius(radius){}

Circle::Circle(const Circle& rhs) 
    : Shape(rhs),
    radius(rhs.radius){}

Circle& Circle::operator=(const Circle& rhs){
    if(this==&rhs){
        return *this;
    }
    else{
        //Deleting and creating new memory for shapeName assignment
        delete[] this -> shapeName;
        this->shapeName = new char[strlen(rhs.getName()) + 1];
        strcpy(this->shapeName, rhs.getName());
        this->radius = rhs.radius;
        return *this;
    }
}

double Circle::area(){
    return 3.14159 * pow(this->radius, 2);
}

double Circle::perimeter(){
    return 3.14159 * 2 * this->radius;
}

double Circle::get() const{
    return this->radius;
}

void Circle::set(double radius) {
    this->radius = radius;
}

void Circle::display() {
    cout << "Circle Name: " << shapeName << endl;
    this->origin.display();
    cout << "Radius: " << radius << endl;
}


