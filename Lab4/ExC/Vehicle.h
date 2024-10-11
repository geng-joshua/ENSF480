/* Vehicle.h 
* Assignment: Lab 3 Exercise C
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Oct 11, 2024
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Moveable.h"
using namespace std;

class Vehicle {
    protected:
    string name;

    public:
    Vehicle(string name);
    void move();
};

#endif // VEHICLE_H
