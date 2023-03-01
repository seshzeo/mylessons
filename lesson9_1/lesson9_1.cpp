#include <iostream>
#include <math.h>
#define DEBUG 0
using namespace std;

class CreditCalc {
private:
    float _credit_sum;
    float _percent;
    int _credit_term;
    float **_calc_res;
    int cols = 4;
    int _month_for_e_pay;
    float _sum_for_e_pay;
public:
    CreditCalc(float credit_sum, float percent, int credit_term) {
        if (credit_sum < 1000 || percent < 0 || credit_term < 1) {
            throw invalid_argument("Неверные значения аргументов.");
        } else {
            this->_credit_sum = credit_sum;
            this->_percent = percent/(12*100);
            this->_credit_term = credit_term*12;
            this->_calc_res = new float *[_credit_term];
            for (int i = 0; i < this->_credit_term; i++)
            {
                this->_calc_res[i] = new float[cols];
            }
            calculate();
        }
    }

    void new_values(float credit_sum, float percent, int credit_term) {
        if (credit_sum < 1000 || percent <= 0 || credit_term < 1) {
            throw invalid_argument("Неверные значения аргументов.");
        } else {
            for (int i = 0; i < this->cols; i++)
            {
                delete[] _calc_res[i];
            }
            delete[] _calc_res;

            this->_credit_sum = credit_sum;
            this->_percent = percent/(12*100);
            this->_credit_term = credit_term*12;
            this->_calc_res = new float *[_credit_term];
            for (int i = 0; i < this->_credit_term; i++)
            {
                this->_calc_res[i] = new float[cols];
            }
            calculate();
        }
    }

    void set_new_early_payment(float sum_for_e_pay, int month_for_e_pay) {
        if (month_for_e_pay >= this->_credit_term || month_for_e_pay <= 0) {
            throw invalid_argument("Выбранный месяц превышает общий срока платежа, либо меньше нуля.");
        } else {
            this->_month_for_e_pay = month_for_e_pay-1;
        }
        if (sum_for_e_pay >= this->_credit_sum || sum_for_e_pay <=0) {
            throw invalid_argument("Сумма досрочного погашения выше суммы кредита, либо меньше нуля.");
        } else {
            this->_sum_for_e_pay = sum_for_e_pay;
        }
    }

    void calculate() {
        float month_fee;
        float leave_to_pay = this->_credit_sum;
        float payment_percent;
        float total_rate;
        total_rate = pow(1 + this->_percent, this->_credit_term);
        
        for (int i = 0; i < this->_credit_term; i++)
        {
            month_fee = this->_credit_sum * this->_percent * total_rate / (total_rate - 1);
            if (leave_to_pay <= month_fee) {
                month_fee = leave_to_pay+(this->_percent * leave_to_pay);
            } else {
                if (i == this->_month_for_e_pay && _sum_for_e_pay != 0) {
                    if (this->_sum_for_e_pay < month_fee) {
                        throw invalid_argument("Сумма досрочного погашения долга должна быть больше ежемесячного платежа.");
                    }
                    if (this->_sum_for_e_pay >= leave_to_pay) {
                        throw invalid_argument("Сумма досрочного погашения выше суммы остаточного долга.");
                    } else {
                        month_fee = _sum_for_e_pay;
                    }
                } else {
                    month_fee = this->_credit_sum * this->_percent * total_rate / (total_rate - 1);
                }
            }
            leave_to_pay -= (month_fee-(this->_percent * leave_to_pay));
            
            for (int j = 0; j < this->cols; j++)
            {
                switch (j)
                {
                case 0:
                    this->_calc_res[i][j] = i+1;
                    break;
                case 1:
                    this->_calc_res[i][j] = month_fee;
                    break;
                case 2:
                    this->_calc_res[i][j] = leave_to_pay;
                    break;
                case 3:
                    this->_calc_res[i][j] = this->_percent * leave_to_pay;
                    break;
                
                default:
                    break;
                }
            }
        }
    }
                    
    void show_fees() {
        printf("%20s%20s%20s%26s", "Месяц", "Платеж", "Остаток", "Процент");
        cout << endl;
        for (int i = 0; i < this->_credit_term; i++)
        {
            for (int j = 0; j < this->cols; j++) 
            {
                if (j != 0) {
                    printf("%14.2f%s",this->_calc_res[i][j], " ₽");
                } else {
                    printf("%14.0f",this->_calc_res[i][j]);
                }
            }
            cout << endl;
        }

    }

    ~CreditCalc() {
        for (int i = 0; i < this->cols; i++)
            {
                delete[] _calc_res[i];
            }
        delete[] _calc_res;
    }
};


int main() {
    CreditCalc calc(1540000, 12.5, 5);
    
    float sum, fst_fee, percent, early_pay;
    int years, e_pay_month;
    char avalible_early_pay;

    bool isContinue = true, canSetEPayment = false;
    cout << "Кредитный Калькулятор (учебный проект).\n";
    
    while(isContinue) {
        try
        {
#if DEBUG == 0
            isContinue = false;
            cout << "Введите сумму кредита: ";
            cin >> sum;
            cout << "Введите первоначальный взнос: ";
            cin >> fst_fee;
            if (fst_fee < 0) {
                throw invalid_argument("Первоначальный взнос не может быть отрицательным.");
            }
            cout << "Введите годовой процент (например 12.5): ";
            cin >> percent;
            cout << "И срок кредита в годах: ";
            cin >> years;
            cout << "Планируете закрыть кредит дострочно? [y/n?]: ";
            cin >> avalible_early_pay;
            if (avalible_early_pay == 'y') {
                canSetEPayment = true;
                cout << "Введите сумму для погашения (либо 0, чтобы пропустить): ";
                cin >> early_pay;
                cout << "Введите номер месяца для погашения (1 месяц 2го года записывается\nкак 13, 2й месяц как 14 и т.д): ";
                cin >> e_pay_month;
            } else {
                canSetEPayment = false;
            }
#endif

#if DEBUG == 1
            sum = 1540000;
            fst_fee = 0;
            percent = 12.5;
            early_pay = 0;
            years = 5;
            e_pay_month = 0;
            isContinue = false;
            canSetEPayment = true;
#endif
            calc.new_values(sum-fst_fee, percent, years);
            if (canSetEPayment) {
                calc.set_new_early_payment(early_pay, e_pay_month);
            }
            calc.calculate(); // также автоматически вызывается в конструкторе и при вызове object.new_value()
            cout << "\nВот таблица запланированных платежей\n #################################################\n";
            calc.show_fees();
            cout << "#################################################\n";

        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            system("clear");
            cout << "Попробуйте еще раз...\n";
            cin.clear();
            isContinue = true;
        }
    }

    return 0;
}