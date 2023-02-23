#include <iostream>
#include <cstring>

using namespace std;

void calc();

int main() {
    
    int n = 0;
    int end_loop = 5;
    while(n<end_loop) {
       try
        {
            calc();
        }
        catch(const std::exception& e)
        {
            n++;
            std::cerr << e.what() << "\n";
        }
    }
    n >= end_loop? cout << "Количество попыток исчерпано.\n" : cout <<  "Попробуйте снова...\n";
    
    return 0;
}

void calc() {
    char input[100]{};
    char a_str[100]{};
    char b_str[100]{};
    const char OPS[] = "+-*/";
    char op;
    long int a, b;
    unsigned int op_addr;
    double res;
    
    cout << "Введите выражение для вычисления (пример: 2+1): ";
    cin >> input;
    int input_len = strlen(input);
    
    for (int i = 0; i < input_len; i++)
    {
        for (int j = 0; j < strlen(OPS); j++)
        {
            if(input[i] == OPS[j]){
                op = input[i];
                op_addr = i;
                goto Link;
            }
        }
    }
    throw invalid_argument("Нет знака математической операции.");
    Link:

    for (int i = 0; i < op_addr; i++)
        a_str[i] = input[i];
        
    for (int i = op_addr+1; i < input_len; i++)
        b_str[i-(op_addr+1)] = input[i];
    

    for (int i = 0; i < strlen(input); i++)
    {
        if (i == op_addr)
            continue;
        else {
            if ((int)(input[i])<48 || (int)(input[i])>57) {
                throw invalid_argument("Выражение содержит лишние символы.");
            }
        }
    }

    a = stoi(a_str);
    b = stoi(b_str);

    switch (op)
    {
    case '+':
        res = a+b;
        break;
    case '-':
        res = a-b;
        break;
    case '/':
        res = (double)a/(double)b;
        break;
    case '*':
        res = a*b;
        break;
    default:
        throw invalid_argument("Нет знака мат. операции.");
        break;
    }
    cout << "Результат выражения " << input << "=" << res << endl;
    exit(0);
}