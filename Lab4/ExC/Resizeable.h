/* Resizeable.h 
* Assignment: Lab 3 Exercise C
* Lab Section: B01
* Completed by: Chloe Choi, Joshua Geng
* Submission Date: Oct 11, 2024
*/

#ifndef RESIZEABLE_H
#define RESIZEABLE_H

class Resizeable {
    public:
    virtual void enlarge(int n) = 0;
    virtual void shrink(int n) = 0;
};

#endif // RESIZEABLE_H