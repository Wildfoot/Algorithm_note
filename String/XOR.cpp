#include <iostream>
#define numc 4194303

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
/*
void dfs (int i)
{
    u[i] = true;
    for(int j = 0;j < g[i].size();j++)
    {
        if(!u[g[i][j])
            dfs(g[i][j]);
    }
}
*/

int main()
{
    int n,arr[100000],ans_10;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    bool str[100000][21] = {0},prefix_str[100000][21] = {0},ans[21] = {0};
    for(int i = 0;i < n;i++)//10 -> 2
    {
        for(int j = 0;j < 21;j++)
        {
            str[i][j] = arr[i] % 2;
            arr[i] = arr[i] / 2;
            if(arr[i] == 0)
                break;
        }
    }
    for(int i = 0;i < n;i++)//prefix
    {
        for(int j = 0;j < 21;j++)
        {
            if(i == 0)
                prefix_str[i][j] = str[i][j];
            else
            {
                prefix_str[i][j] = prefix_str[i - 1][j] ^ str[i][j];
            }
        }
    }
///print str
    for(int i = 0;i < n;i++)
    {
        for(int j = 20;j >= 0;j--)
        {
            cout << prefix_str[i][j];
            //cout << str[i][j];
        }
        cout << endl;
    }
//*/
/*//
    root = newNode();
    for(int i=0, where=root; i<len; i++){
        if(edge[where][ str[i]-'a' ] == -1) edge[where][str[i]-'a'] = newNode();
        where = edge[where][str[i]-'a'];
    }
    count[where]++;
//*/    
    root = newNode();
    for(int i = 0;i < n;i++)//make tree
    {
        int where = root;
        for(int j = 20;j >= 0;j--)
        {
            //cout << "where=" << where << "prefix_ij" << i << " " << j <<" | " << prefix_str[i][j] << endl;
            if(edge[where][ prefix_str[i][j] ] == -1)
                edge[where][ prefix_str[i][j] ] = newNode();
            where = edge[where][ prefix_str[i][j] ];
        } 
        count[where]++;
        //cout << "where="<< where << endl;
    }
    
    for(int i = 0;i < n;i++)
    {
        bool Target[21],Sans[21] = {0},flag = 0;
        for(int j = 0;j < 21;j++)
            Target[j] = 1 - prefix_str[i][j];

        for(int j = 21;j >= 0;j--)
        {
            if(Sans[j] > ans[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            for(int j = 0;j < 21;j++)
            {
                ans[j] = Sans[j];
            }
    }
    for(int i = 0;i < 21;i++)
    {
        if(ans[i])
        {
            int temp = 1;
            for(int j = 0;j < 20 - i;j++)
                temp = temp * 2;
            ans_10 = ans_10 + temp;
        }
    }
    cout << ans_10 << " ";
}

