#include <string>
using namespace std;

class Moveable {
    public:
    virtual void forward();
    virtual void backward();
};

class Resizable {
    public:
    virtual void enlarge(int n);
    virtual void shrink(int n);
};

class Vehicle {
    protected:
    string name;

    public:
    void forward();
    void backward();
    void enlarge(int n);
    void shrink(int n);
    Vehicle(string name);
    void move();
};

class Car final : public Vehicle {
    private:
    int seats;

    public:
    void turn();
};