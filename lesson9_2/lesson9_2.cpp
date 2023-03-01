#include <iostream>
#include <string.h>

using namespace std;

bool canMove(const wchar_t* , const wchar_t* , int &); //рекурсивная функция сравнивания фамилий побуквенно

int main() {
    setlocale(LC_CTYPE, "");
    const wchar_t* surnames[] {
        L"Курышкин",
        L"Семенов",
        L"Аркадьев",
        L"Якушев",
        L"Леонов",
        L"Марусин",
        L"Кондратьев",
        L"Михайлов",
        L"Прокопенко",
        L"Соловьев",
        L"Мишустин",
        L"Карамзин",
        L"Арсеньев",
        L"Петросян",
        L"Яковлев",
        L"Назаров",
        L"Калинина",
        L"Калинин",
        L"Миронова",
        L"Миронов",
        L"Михайлова",
        L"Курышкина",
        L"Семенова",
        L"Аркадьева",
        L"Якушева",
        L"Леонова",
        L"Марусина",
        L"Кондратьева"
    };
    int size = sizeof(surnames)/sizeof(surnames[0]);
    bool isContinue = true;

    while (isContinue) {
        isContinue = false;
        for (int i = 0; i < size-1; i++)
        {
            int count = 0;
            if (canMove(surnames[i],surnames[i+1], count)) {
                const wchar_t* temp = surnames[i+1];
                surnames[i+1] = surnames[i];
                surnames[i] = temp;
                isContinue = true;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        wcout << surnames[i] << endl;
    }
    
    return 0;
}


bool canMove(const wchar_t* _lhs_str, const wchar_t* _rhs_str, int &count) {
    if ((int)_lhs_str[count] == (int)_rhs_str[count]) {
        count++;
        return canMove(_lhs_str, _rhs_str, count);
    }
    else if ((int)_lhs_str[count] > (int)_rhs_str[count]) {
        return true;
    }
    else {
        return false;
    }
}