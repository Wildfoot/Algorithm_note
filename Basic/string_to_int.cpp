#include<iostream>

using namespace std;

int string_to_int(string s,int x,int y)
{
    int n = y - x;
    int total = 0;
    for(int i = n;i > 0;i--)
    {
        int temp = s[x - i + n] - '0';
        for(int j = 1;j < i;j++)
        {
            temp *= 10;
        }
        total += temp;
    }
    return total;
}
int main()
{
    string s = "1010";
    cout << string_to_int(s, 0, 4);
    return 0;
}
