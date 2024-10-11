/* Car.h 
* Assignment: Lab 3 Exercise C
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Oct 11, 2024
*/

#ifndef CAR_H
#define CAR_H

#include <string>
#include <Vehicle.h>
using namespace std;

class Car final : public Vehicle {
    private:
    int seats;

    public:
    void turn();
};

#endif // CAR_H
