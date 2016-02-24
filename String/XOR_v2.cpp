//NTHU7354 Cow XOR
#include <iostream>
#define numc 8388607
//#define numc 4194303

using namespace std;

int edge[numc][2];    //2^21-1 = 111111111111111111111(21)
int count[numc];
int p = 0;
int root;
int newNode()
{
    int ind = p;
    p++;
    for(int i = 0;i < 2;i++)
        edge[ind][i] = -1;
    count[ind] = 0;
    return ind;
}

int main()
{
    int n,arr[100001],ans_10,ans2 = 0,ans3 = 0;

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    
    root = newNode();
    bool str[100001][21] = {0},ans[21] = {0},Sans2[21] = {0};
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j < 21;j++)
        {
            str[i][j] = arr[i] % 2;
            arr[i] = arr[i] / 2;
            if(i == 1||i == 0)
                str[i][j] = str[i][j];
            else
            {
                str[i][j] = str[i - 1][j] ^ str[i][j];
            }
        }
        /*
        cout << "str" << i << " = ";
        for(int j = 20;j >= 0;j--)
            cout << str[i][j];
        cout << endl;
        */
       
        bool Target[21],Sans[21] = {0},flag = 0;
        int ptr = 0;
        for(int j = 0;j < 21;j++)
            Target[j] = 1 - str[i][j];
        /*
        cout << "Target" << i << " = ";
        for(int j = 20;j >= 0;j--)
            cout << Target[j];
        cout << endl;
        */

        if(i > 1)
            for(int k = 20;k >= 0;k--)
            {
                //cout << "edge[ptr][Target[k]]" <<  edge[ptr][Target[k]] << endl;

                if(edge[ptr][ Target[k] ] == -1)
                {
                    Sans[k] = 0;
                    ptr = edge[ptr][ 1 - Target[k] ];
                }
                else
                {
                    Sans[k] = 1;
                    ptr = edge[ptr][ Target[k] ];
                }
            }
        /*
        cout << "Sans" << i << " = ";
        for(int j = 20;j >= 0;j--)
            cout << Sans[j];
        cout << endl;
        */


        int where = root;

        for(int j = 20;j >= 0;j--)
        {
            if(edge[where][ str[i][j] ] == -1)
                edge[where][ str[i][j] ] = newNode();
            where = edge[where][ str[i][j] ];
        } 
        count[where] = i;
        //cout << "where= " << where << endl;

        for(int j = 21;j >= 0;j--)
        {
            if(Sans[j] > ans[j])
            {
                flag = 1;
                break;
            }
            else if(Sans[j] < ans[j])
            {
                break;
            }
        }
        //cout << "flag = " << flag << endl;
        if(flag)
        {
            ans3 = i;
            for(int j = 0;j < 21;j++)
            {
                ans[j] = Sans[j];
            }
            ans2 = count[ptr] + 1;
        }
        /*
        cout << "ans" << i << " = ";
        for(int j = 20;j >= 0;j--)
            cout << ans[j];
        cout << endl;
        */

    }
   

    for(int i = 20;i >= 0;i--)
    {
        if(ans[i])
        {
            int temp = 1;
            for(int j = 0;j < i;j++)
                temp = temp * 2;
            ans_10 = ans_10 + temp;
        }
    }
    cout << ans_10 << " " << ans2 << " " << ans3 << endl;
}
