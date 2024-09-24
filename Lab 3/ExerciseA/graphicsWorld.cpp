/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 2 Exercise B
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Sept 20, 2024
*/

#include "graphicsWorld.h"
#include <string.h>
#include <iostream>
using namespace std;


void GraphicsWorld::run(){
#if 1 // Change 0 to 1 to test Point
    Point m (6, 8);
    Point n (6,8);
    n.setx(9);
    cout << "\nExpected to dispaly the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
    << Point::distance(m, n);
#endif // end of block to test Point
#if 1 // Change 0 to 1 to test Square
    cout << "\n\nTesting Functions in class Square:" <<endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
#endif // end of block to test Square
#if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:";
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16 , 7, 8, 9, "RECTANGLE B");
    b.display();
    double d = a.distance(b);
    cout <<"\nDistance between square a, and b is: " << d << endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" <<endl;
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    //error begins here.
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 12\n" << "Side b: 15\n" << "Area: 180\n" << "Perimeter: 54\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec2.display();
    cout << "\nTesting copy constructor in class Rectangle:" <<endl;
    Rectangle rec3 (a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 100\n" << "Side b: 200\n" << "Area: 20000\n" << "Perimeter: 600\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec3.display();
#endif // end of block to test Rectangle
#if 1 // Change 0 to 1 to test using array of pointer and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" <<endl;
    Shape* sh1[4];
    sh1[0] = &s;
    sh1[1] = &b;
    sh1 [2] = &rec1;
    sh1 [3] = &rec3;
    sh1 [0]->display();
    sh1 [1]->display();
    sh1 [2]->display();
    sh1 [3]->display();
#endif // end of block to test array of pointer and polymorphism
//Tests for curvecut and circle.
#if 0  
    cout << "Testing circle constructor for c1" <<endl;
    Circle c1(10, 1, 2, "CIRCLE 1");
    c1.display();

    cout << "Testing circle constructor for c2" <<endl;
    Circle c2(3, 4, 2, "CIRCLE 2");
    c2.display();

    cout << "Testing copy constructor for c3 copies c1" <<endl;
    Circle c3(c1);
    c3.display();

    cout << "Testing circle constructor for c4" << endl;
    Circle c4(13, 2, 9, "CIRCLE 4");
    c4.display();

    cout << "Testing assignment operator so that c1 now equals c4" << endl;
    c1 = c4;
    c1.display();

    cout << "Testing curvecut constructor for cc1" << endl;
    Curvecut cc1(0, 1, 9, 4, 2, "CURVECUT 1");
    cc1.display();

    cout << "Testing area for cc1" << endl;
    cout << cc1.area() << endl;
    cout << "Testing perimeter for cc1" << endl;
    cout << cc1.perimeter() << endl;

#endif
/****************************ASSUME CODE SEGMENT FOR EXERCISE A IS HERE ************************/
#if 1
    cout << "\nTesting Functions in class Circle:" <<endl;
    Circle c (3, 5, 9, "CIRCLE C");
    c.display();
    cout << "the area of " << c.getName() <<" is: "<< c.area() << endl;
    cout << "the perimeter of " << c.getName() << " is: "<< c.perimeter() << endl;
    d = a.distance(c);
    cout << "\nThe distance between rectangle a and circle c is: " <<d;
    Curvecut rc (6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    cout << "the area of " << rc.getName() <<" is: "<< rc.area();
    cout << "the perimeter of " << rc.getName() << " is: "<< rc.perimeter();
    d = rc.distance(c);
    cout << "\nThe distance between rc and c is: " <<d;
    // Using array of Shape pointers:
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &a;
    sh [2] = &c;
    sh [3] = &rc;
    sh [0]->display();
    cout << "\nthe area of "<< sh[0]->getName() << "is: "<< sh[0] ->area();
    cout << "\nthe perimeter of " << sh[0]->getName () << " is: "<< sh[0]->perimeter();
    sh [1]->display();
    cout << "\nthe area of "<< sh[1]->getName() << "is: "<< sh[1] ->area();
    cout << "\nthe perimeter of " << sh[0]->getName () << " is: "<< sh[1]->perimeter();
    sh [2]->display();
    cout << "\nthe area of "<< sh[2]->getName() << "is: "<< sh[2] ->area();
    cout << "\nthe circumference of " << sh[2]->getName ()<< " is: "<< sh[2]->perimeter();
    sh [3]->display();
    cout << "\nthe area of "<< sh[3]->getName() << "is: "<< sh[3] ->area();
    cout << "\nthe perimeter of " << sh[3]->getName () << " is: "<< sh[3]->perimeter();
    cout << "\nTesting copy constructor in class CurveCut:" <<endl;
    Curvecut cc = rc;
    cc.display();
    cout << "\nTesting assignment operator in class CurveCut:" <<endl;
    Curvecut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display();
#endif
}

int main() {
    cout << "\nThe authors of this program were Chloe Choi and Joshua Geng." << endl;
    // Create an instance of GraphicsWorld
    GraphicsWorld gw;

    // Call the run method to test various functionalities
    gw.run();

    return 0;
}

