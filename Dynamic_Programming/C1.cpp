#include <iostream>

using namespace std;

bool dp[999][999];

int fun(int x,int y)
{
    if(x == 0 && y == 0)
        return 1;
    else if(x == 0)
        return fun(x ,y - 1);
    else if(y == 0)
        return fun(x - 1 ,y);
    else if(x >= 0 && y >= 0)
        return fun(x - 1,y) + fun(x ,y - 1);

}

int main()
{
    int n ,m;
    cin >> m >> n;
    m--;
    n--;
    cout << fun(m ,n) << endl;
}
