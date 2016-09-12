#include <iostream>
#define INF 2147483647

using namespace std;

int main()
{
    int in[99][2],dp[99][99] = {0},m ,l, ans = 0;  //dp[i][j]=前面i個物品湊出剛好重量為j的價值為多少
    cin >> m >> l;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            cin >> in[i][j];
        }
    } 
    

    //初始值  
    //X  0 1 2 3 4 5 6 7 8 //重量
    //___________________                            V     W
    //0  0 - - 2 - - - - -   //初始第一個物品        2     3
    //1  0 - 3 2 - 5 - - -                           3     2
    //2  0 1 3 4 3 5 6 - -                           1     1
    //3  0 1 3 4 8 9 11 12 11                        8     4
    //前面幾個物品
    
    for(int i = 0;i <= l;i++)   dp[0][i] = -INF;
    dp[0][0] = 0;
    dp[0][in[0][1]] = in[0][0]; 

    for(int i = 1;i < m;i++)
    {   
        for(int j = 0;j <= l;j++)
        {
            if(j < in[i][1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j - in[i][1]] + in[i][0];
                if(dp[i][j] < dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 0;i <= l;i++)
        if(ans < dp[m - 1][i])
            ans = dp[m - 1][i];

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j <= l;j++)
        {
            if(dp[i][j] < 0)
                cout << "- ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << ans << endl;
}
