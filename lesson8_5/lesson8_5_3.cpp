#include <iostream>

using namespace std;

class Fraction {
private:
    int _numerator;
    int _denuminator;
public:
    Fraction(){};
    Fraction(int numerator, int denumirator)
    {
        if (denumirator == 0) {
            throw invalid_argument("Знаменатель не может быть равен нулю");
        } else {
            this->_denuminator = denumirator;
            this->_numerator = numerator;
        }
        reduction(this->_numerator, this->_denuminator);
    }

    void sign_correction(int &_num, int &_den) {
            if(_den < 0) { 
                _num = -_num;
                _den = -_den;
            }
        }

    void reduction(int &_num, int &_den) {
        int n = _den < _num? _den : _num;
        if (n < 0){ n = -n; }
        for (int i = 2; i <= n; )
        {
            if(_den%i == 0 && _num%i == 0) {
                _den /= i;
                _num /= i;
                n/=i;
            } else { i++; }
        }
        sign_correction(_num, _den);
    }

    Fraction operator + (const Fraction& other) {
        Fraction res((this->_numerator*other._denuminator)-(other._numerator*this->_denuminator),
        this->_denuminator * other._denuminator);
        return res;
    }

    Fraction operator - (const Fraction& other) {
        Fraction res((this->_numerator*other._denuminator)-(other._numerator*this->_denuminator),
        this->_denuminator * other._denuminator);
        return res;
    }

    Fraction operator * (const Fraction& other) {
        Fraction res(this->_numerator * other._numerator, this->_denuminator * other._denuminator);
        return res;
    }

    Fraction operator / (const Fraction& other) {
        Fraction res(this->_numerator * other._denuminator, this->_denuminator * other._numerator);
        return res;
    }

    Fraction operator - () {
        return Fraction(-_numerator, _denuminator);
    }

    bool operator == (const Fraction& other) {
        return (other._numerator == this->_numerator && other._denuminator == this->_denuminator);
    }

    bool operator != (const Fraction& other) {
        return (other._numerator != this->_numerator && other._denuminator != this->_denuminator);
    }

    friend bool operator < (const Fraction& _lhs, const Fraction& _rhs);
    friend bool operator >= (const Fraction& _lhs, const Fraction& _rhs);
    friend bool operator > (const Fraction& _lhs, const Fraction& _rhs);
    friend bool operator <= (const Fraction& _lhs, const Fraction& _rhs);

    void prinffr() {
        cout << this->_numerator << "/" << this->_denuminator;
    }
};

bool operator < (const Fraction& _lhs, const Fraction& _rhs) {
    float lhs = (float)_lhs._numerator/(float)_lhs._denuminator;
    float rhs = (float)_rhs._numerator/(float)_rhs._denuminator;
    return (lhs < rhs);
}

bool operator >= (const Fraction& _lhs, const Fraction& _rhs) {
    return (!(_lhs < _rhs));
}

bool operator > (const Fraction& _lhs, const Fraction& _rhs) {
    float lhs = (float)_lhs._numerator/(float)_lhs._denuminator;
    float rhs = (float)_rhs._numerator/(float)_rhs._denuminator;
    return (lhs > rhs);
}

bool operator <= (const Fraction& _lhs, const Fraction& _rhs) {
    return (!(_lhs > _rhs));
}

int main() {
    Fraction fr1(15,99);
    Fraction fr2(15,98);
    Fraction res = fr1 / fr2;
    res.prinffr();
    cout << endl;
    fr1.prinffr();
    cout << endl;
    fr2.prinffr();
    cout << endl;
    bool b_res;
    b_res = fr1 > fr2;
    cout << "> " << b_res << endl;
    b_res = fr1 < fr2;
    cout<< "< "  << b_res << endl;
    b_res = fr1 >= fr2;
    cout<< ">= "  << b_res << endl;
    b_res = fr1 <= fr2;
    cout<< "<= "  << b_res << endl;
    b_res = fr1 == fr2;
    cout<< "== "  << b_res << endl;
    b_res = fr1 != fr2;
    cout<< "!= "  << b_res << endl;

    return 0;
}