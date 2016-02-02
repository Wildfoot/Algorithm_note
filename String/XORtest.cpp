#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
    int x;
    cin >> x;
    int temp = 1,total = 1;
    for(int i = 0;i < x;i++)
    {
        temp = temp * 2;
        total = total + temp;
    }
    cout << total << endl;

}}

