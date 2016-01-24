#include <iostream>

using namespace std;

int main()
{
    int arr[99],sum = 0,n,ans = 0;
    while(cin >> n)
    {
        if(!n)
            break;
        if(sum + n > 0)
        {
            sum = sum + n;
            if(sum > ans)
            {
                ans = sum;
            }
        }
        else
        {
            sum = 0;
        }
    }
    cout << ans << endl;
    
}
