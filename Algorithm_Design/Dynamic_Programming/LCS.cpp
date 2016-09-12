#include <iostream>
#include <string>
using namespace std;

//dp[length.x + 1][length.y + 1]
int dp[999][999];
char sx[999],sy[999];

int main()
{
    int m ,n;
    string s;
    cin >> m >> n;
    getline(cin, s);
    getline(cin, s);
    for(int i = 1;i <= m;i++)
    {   
        sx[i] = s[i - 1];
 //       cout << sx[i];
    }

    getline(cin, s);
    for(int j = 1;j <= n;j++)
    {   
        sy[j] = s[j - 1];
    //    cout << sy[j];
    }
    

    

    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(sx[i] == sy[j]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if(dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }        
    }

    ///////////////////////////////////////
     cout << " ";
     for(int j = 1;j <= n;j++)
            cout << sy[j];
     cout << endl;
     for(int i = 1;i <= m;i++)
     {   
                  cout << sx[i];
         for(int j = 1;j <= n;j++)
         {
            cout << dp[i][j];
         }
         cout << endl;
     }    
     ///////////////////////////////////////
    cout << endl << dp[m][n];
}
