/*
* File Name: point.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#include "point.h"
#include <string.h>
#include <iostream>


int Point::objectCounter = 0;
int Point::idnum = 1001;

void Point::display() {
    cout << "X-coordinate: " << this->x << "\nY-coordinate: " << this->y << endl;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
    this->id = idnum;
    objectCounter++;
    idnum++;
}


double Point::getx(){
    return this->x;
}

double Point::gety(){
    return this->y;
}

int Point::getid(){
    return this->id;
}

void Point::setx(double x){
    this->x = x;
}

void Point::sety(double y){
    this->y = y;
}

double Point::distance(Point& s){
    double x = this->x - s.getx();
    double y = this->y - s.gety();
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Point::distance(Point& lhs, Point& rhs){
    double newx = lhs.getx() - rhs.getx();
    double newy = lhs.gety() - rhs.gety();
    return sqrt(newx * newx + newy * newy);
}