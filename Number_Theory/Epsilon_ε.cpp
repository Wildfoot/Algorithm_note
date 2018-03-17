// 
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cmath>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

// Float - 
//     Number range:-3.4e-38 ~ 3.4e38
//     十位數精確度數:6~7
// Double - 
//     Number range:-1.7e308~1.7e308
//     十位數精確度數:14~15

// a == b       abs(a - b) < EPS
// a != b       abs(a - b) > EPS
// a < b        a - b < -EPS
// a > b        a - b > EPS

void example()
{
    double a = asin(sqrt(2.0) / 2) * 4.0;
    double b = acos(-1.0);

    printf("a = %.20lf\n", a);
    printf("b = %.20lf\n", b);
    printf("a - b = %.20lf\n", a - b);
    printf("a == b? %s\n", a == b ? "True" : "False");
    printf("a == b? %s\n", abs(a - b) < EPS ? "True" : "False");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    example();

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

