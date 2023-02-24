#include <iostream>
#include <math.h>

using namespace std;

class Function {
public:
    float y;
    virtual void f(float x) {
        cout << "f(x) при y = x, x = " << x << endl;
    }
};

class Ellipse : public Function {
public:
    void f(float x) override {
        
        if(x>=-1 && x<=1) {
            float y2;
            this->y = sqrt(1-x*x);
            y2 = -sqrt(1-x*x);
            cout << "При х = " << x << " в f(x) = (1-x^2)/y (Эллипс) y1 = " << this->y << ", y2 = " << y2 << endl;
        } else {
            cout << "При х = " << x << " в f(x) = (1-x^2)/y (Эллипс) y не определен" << endl;
        }
    }
};

class Hiperbola : public Function {
public:
    void f(float x) override {
        if (x == 0) {
            cout << "При х = 0 в функции f(x) = 1/x (Гипербола) y равен бесконечности" << endl;
        } else {
            this->y = 1/x;
            cout << "При х = " << x << " в функции f(x) = 1/x (Гипербола) y = " << this->y << endl;
        }
    }
};

class Parabola : public Function {
public:
    void f(float x) override {
        this->y = x*x;
        cout << "При х = " << x << " в функции f(x) = x^2 (Парабола) y = " << this->y << endl;
    }
};

enum func_type {
    LINE_TP, ELLIPSE_TP, HIPERB_TP, PARAB_TP
};

Function* create_any_Function(func_type type) {
    switch (type) {
    case LINE_TP:
        return new Function;
        break;
    case ELLIPSE_TP:
        return new Ellipse;
        break;
    case HIPERB_TP:
        return new Hiperbola;
        break;
    case PARAB_TP:
        return new Parabola;
        break;
    default:
        throw runtime_error("Неизвестный тип фигуры!");
        break;
    }
}

int main() {
    float x = 0.5;
    Function line;
    Ellipse ell;
    Hiperbola hip;
    Parabola parab;
    Function* funcs[] {&line, &ell, &hip, &parab};
    
    for (int i = 0; i < 4; i++) {
        funcs[i]->f(x);
    }
    
    Function* ell2 = create_any_Function(ELLIPSE_TP);
    ell2->f(10);
    return 0;
}