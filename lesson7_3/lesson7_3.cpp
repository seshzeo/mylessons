#include <iostream>

using namespace std;

double square_root(int);
void square_root(int,double*);
void square_root(int,double&);

int main()
{
    double root1,root2,root3;
    int a,b,c;
    cout << "Введите 3 числа через пробел, корни которых вы хотете узнать: ";
    cin >> a >> b >> c;
    root1 = square_root(a);
    square_root(b, &root2);
    square_root(c, &root3);
    cout << "Корень первого числа равен " << root1 << endl;
    cout << "Корень второго числа равен " << root2 << endl;
    cout << "Корень третьего числа равен " << root3 << endl;
    return 0;
}


double square_root(int a)
{
    double root = (double)a;
    double limit = 0.00001;
    while(root*root-a>=limit)
    {
        root = (root+a/root)/2;
    }
    return root;
}

void square_root(int a, double *proot)
{
    double root = (double)a;
    double limit = 0.00001;
    while(root*root-a>=limit)
    {
        root = (root+a/root)/2;
    }
    *proot = root;
}

void square_root(int a, double &rootRef)
{
    double root = (double)a;
    double limit = 0.00001;
    while(root*root-a>=limit)
    {
        root = (root+a/root)/2;
    }
    rootRef = root;
}

