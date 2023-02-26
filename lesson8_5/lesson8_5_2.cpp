#include <iostream>

using namespace std;

class Car {
protected:
    string _company;
    string _model;
public:
    Car(){};
    Car(string company, string model) : _company(company), _model(model) {
        cout << this->_company << this->_model << endl;
    }
    void my_void() {
        cout<<this<<endl;
    }
};

class PassengerCar : public virtual Car {
public:
    PassengerCar(){};
    PassengerCar(string company, string model) {
        this->_company = company;
        this->_model = model;
        cout << this->_company << this->_model << endl;
    }
};

class Bus : public virtual Car {
public:
    Bus(){};
    Bus(string company, string model) {
        this->_company = company;
        this->_model = model;
        cout << this->_company << this->_model << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(){};
    Minivan(string company, string model) {
        this->_company = company;
        this->_model = model;
        cout << this->_company << this->_model << endl;
    }
};

int main() {
    
    Car car1("Toyota", "Camry");
    PassengerCar car2("Honda", "Civic");
    Bus car3("GAZel", "Sobol");
    Minivan car4("Dodge", "Grand Caravan");

    return 0;
}