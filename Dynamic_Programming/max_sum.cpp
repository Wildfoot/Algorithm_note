#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int keyin = 0,n;
    long long sum = 0,ans = -2147483647;
    scanf("%d" ,&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&keyin);
        /*
        if(sum + keyin > 0)
        {
            sum = sum + keyin;
            if(sum > ans)
            {
                ans = sum;
            }
        }
        else
        {
            sum = 0;
        }
        */
        if(sum < 0)
            sum = 0;
        sum += keyin;
        if(sum > ans)
        {
            ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
