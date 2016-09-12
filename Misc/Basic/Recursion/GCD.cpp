#include <iostream>

using namespace std;

int GCD(int a,int b)
{
    if(!b)
        return a;
    else
        return GCD(b, a % b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << GCD(n, m);
    return 0;
}
