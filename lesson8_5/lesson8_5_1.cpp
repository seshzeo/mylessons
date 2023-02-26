#include <iostream>

using namespace std;

class Figure {
public:
    Figure(){}
    virtual float area() = 0;
};

class Parallelogram : public Figure {
private:
    float _a, _b, _h;
public:
    Parallelogram(float a, float b, float h) : _a(a), _b(b), _h(h) {
        if (a<0 || b<0 || h<0) {
            throw invalid_argument("Стороны или высота должны быть больше нуля");
        }
    }
    float get_a() { return this->_a; }
    float get_h() { return this->_h; }
    float get_b() { return this->_b; }
    virtual float area() override { return (this->_b * this->_h); }
};

class Circle : public Figure {
private:
    float _r;
public:
    Circle(float r) : _r(r) {
        if (r<0) {
            throw invalid_argument("Радиус должен быть больше нуля");
        }
    };
    float get_r() { return this->_r; }
    virtual float area() override { return (3.1416 * this->_r * this->_r); }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(float a, float b) : Parallelogram( a, b, b ) {}
    virtual float area() override { return (this->get_a() * this->get_b()); }
};

class Square : public Parallelogram {
public:
    Square(float a) : Parallelogram( a, a, a ) {}
    virtual float area() override { return (this->get_a()*this->get_a()); }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float a, float h) : Parallelogram(a, a, h) {}
    virtual float area() override { return (this->get_a() * this->get_h()); }
};

int main() {
    try
    {
        Figure* figures[] = {
            new Parallelogram(5.8, 10.2, 3.02),
            new Circle(5.15),
            new Rectangle(6.23, 10),
            new Square(3.4),
            new Rhombus(13.9, 6.44)
        };

        for (auto figure : figures) {
            cout << "Площадь " << figure << " равна " << figure->area() << endl;
            delete figure;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}