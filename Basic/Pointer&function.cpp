#include <iostream>

using namespace std;

int fun(int *T)
{
    cout << T << endl;
    cout << *T << endl;
    *T = 200;
    return 10;
}

int main()
{
    int A = 10,B;
    B = fun(&A);
    
    cout << A << endl;
}
