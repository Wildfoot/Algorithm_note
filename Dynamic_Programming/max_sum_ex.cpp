#include <iostream>

#define MAXN 99
using namespace std;
// O(n^4)
int main()
{
    int in[MAXN][MAXN] = {0},prefix[MAXN][MAXN] = {0},prefix_ex[MAXN][MAXN] = {0},m,n;
    //prefix 
    //1 2 3 4 5   ->    1 3 6 10 15
    //prefix_ex
    //1 2 3 4 5         1 3 6 10 15
    //2 3 4 5 6   ->    3 8 15 24 35  //左上角到點的面積
    //3 4 5 6 7         6 15 27 42 60
    cin >> m >> n;
    for(int i = 0;i < m;i++)
    {
        int temp = 0;
        for(int j = 0;j < n;j++)
        {
            cin >> in[i][j];
            temp = temp + in[i][j];
            prefix[i][j] = temp;
        }
    }
    for(int i = 0;i < n;i++)
    {
        int temp = 0;
        for(int j = 0;j < m;j++)
        {
            temp = temp + prefix[j][i];
            prefix_ex[j][i] = temp;
        }
    }
    

    /*
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            //cout << in[i][j] << " ";
            //cout << prefix[i][j] << " ";
            cout << prefix_ex[i][j] << " ";
        }
        cout << endl;
    }
    //*/
    int keyin[2][2], t;
    cin >> t;
    while(t--)
    {
        int ans = 0;
        for(int i = 0;i < 2;i++)
        {
            cin >> keyin[i][0];
            cin >> keyin[i][1];
            keyin[i][0]++;
            keyin[i][1]++;
        }
        ans = prefix_ex[keyin[1][0]][keyin[1][1]];
        ans = ans + prefix_ex[keyin[0][0] - 1][keyin[0][1] - 1];
        ans = ans - prefix_ex[keyin[1][0]][keyin[0][1] - 1];
        ans = ans - prefix_ex[keyin[0][0] - 1][keyin[1][1]];
        cout << ans << endl;
    }
    return 0;
}
