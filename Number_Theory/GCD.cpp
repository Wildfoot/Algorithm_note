#include <iostream>

using namespace std;

//Euclidean Algorithm
int GCD(int a, int b)
{
    if(!b)
        return a;
    else
        return GCD(b, a % b);
}

//GCD(30, 47)                       47x + 30y = 1
//GCD(47, 30) 47 = 30 * 1 + 17      17 = 47 * 1 + 30 * -1
//GCD(30, 17) 30 = 17 * 1 + 13      13 = 30 * 1 + 17 * -1
//GCD(17, 13) 17 = 13 * 1 + 4        4 = 17 * 1 + 13 * -1
//GCD(13,  4) 13 = 4 * 3 + 1         1 = 13 * 1 +  4 * -3
//GCD( 4,  1) 4 = 1 * 4 + 0
//GCD( 1,  0)

int exGCD(int a, int b, int &X, int &Y)
{
    if(!b)
    {
        X = 1; Y = 0; 
//        cout << a << " * " << X << " + " << b << " * " << Y << " = " << GCD(a, b) << endl;
        return a;
    }
    else
    {
        int ret = exGCD(b, a % b, X, Y);
        swap(X, Y);
        Y = Y - (a / b) * X;
//        cout << a << " * " << X << " + " << b << " * " << Y << " = " << GCD(a, b) << endl;
        return ret;
    }
}

int main()
{
    int n, m, X, Y;
    while(cin >> n >> m)
    {
        //cout << GCD(n, m) << endl;
        cout << "GCD = " << exGCD(n, m, X, Y) << endl;
        cout << n << " * " << X << " + " << m << " * " << Y << " = " << GCD(n, m) << endl;
    }
    return 0;
}
