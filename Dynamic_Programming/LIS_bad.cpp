#include <iostream>

using namespace std;

int main()
{
    int arr[999] = {0},n = 1,dp[999] = {0},table[999] = {0},L = 0,R = 0,k = 0;
    /*
    for(int i = 1;i < 1000;i++)
    {
        //initialization table[0]=-unlimited table[>=1]=unlimited
        table[i] = 9999;
    }
    */

/*/////////////////O(n^2)//////////////////////
    while(cin >> arr[n]) 
    {        
        if(arr[n] == 0) break;
        n++;
    }
    n--;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(arr[j] < arr[i])
            {
                if(dp[i] <= dp[j])
                    dp[i] = dp[j] + 1;
            }
        }
    }   
////////////////////////////////////////////*/
    
    /* 應該是二分搜
    while(cin >> n)
    {
        int m;
        if(!n)
            break;
        while(L <= R)
        {
            if(k == 0)
            {
                table[0] = n;
                R++;
                break;
            }

            m = (L + R) / 2;
            if(n > table[m])
            {
               L = m;
            }
            else if(n < table[m])
            {
                if(n < table[m + 1] || table[m + 1] == 0)
                {
                    table[m] = n;
                    R++;
                    break;
                }
    
                R = m;
            }
        }
    }
    */

    for(int i = 0;i < 999;i++) table[i] = 9999;
    table[0] = 0;


    int W = 0;
    while(cin >> n)
    {
        if(!n)
            break;
        if(k == 0)
        {
            table[1] = n;
        }
    
        for(int i = 1;i <= 999;i++)
        {
            if(table[i - 1] < n && n < table[i])
            {
                table[i] = n;
                
                if(i > W)
                    W++;
                break;
            }
        }
        k++;
    }

    cout << W;
    //cout << dp[n] << endl;
    return 0;
}
