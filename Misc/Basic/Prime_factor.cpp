#include<iostream>
using namespace std;
int ptr,Prime[169]; //168+1
void Prime_factor(int n)
{
    for(unsigned int i = 2;i <= n;i++)
    {
        while(n % i == 0)
        {
            Prime[ptr] = i;
            ptr++;
            if(Prime[ptr - 1] == Prime[ptr - 2])
                ptr--;
            n = n / i;
        }
    }
}
void initial(int n)
{
    ptr = 1;
    for(int i = 0;i < n;i++)
    {
        Prime[i] = 0;
    }
}
int main()
{
    int in;      //儲存輸入
    while(true)
    {
        cout << "Number:";
        cin >> in;
        /*
        for(unsigned int x = 2;x <= in;x++)
        {
            while(in % x == 0)
            {
                cout << x << "*";
                in /= x;
            }
        }
        cout<<"\b \n";
        */
        initial(in);
        Prime_factor(in);
        for(int i = 1;i < ptr;i++)
        {
            cout << Prime[i] << " ";
        }
        cout << endl;
    } 
    return 0;
}
