/*
* File Name: point.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 27, 2024
*/

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


class Point{
private:
    double x;
    double y;
    int id;
    static int objectCounter;
    static int idnum;
public:
    void display();
    Point(double x, double y);
    double getx();
    double gety();
    int getid();
    void setx(double x);
    void sety(double y);
    double distance(Point& s);
    static int counter(){return objectCounter;}
    static double distance(Point& lhs, Point& rhs);
};



#endif /* point_h */