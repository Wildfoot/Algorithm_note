#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 500

using namespace std;

int n;
int g[MAXN][MAXN], label_x[MAXN], label_y[MAXN], slack_y[MAXN];
//用鄰接矩陣存二分圖，把點分成X、Y兩個集合
//lx[x],ly[y]為x,y的vertex labeling
//slack_y[y]紀錄和y相鄰的最小「非等邊」值
int match_y[MAXN];
//match_y[y]=x表示y和x匹配
bool visit_x[MAXN], visit_y[MAXN];

bool DFS(int x)
{
    if(visit_x[x])  return 0;
    visit_x[x] = true;
    for(int i = 0, d; i < n;i++)
    {
        if(visit_y[y])  continue;
        d = label_x[x] + label_y[y] - g[x][y];
        if(d == 0)
        {
            visit_y = true;
            if(match_y[y] == -1 || DFS(match_y[y]))
            {
                match_y[y] = x;
                return true;
            }
        }
        else
        {
            if(d < slack_y[y])  slack_y[y] = d; //儲存{跟y相接的邊}最小的d
        }
    }
    return false;
}

inline int KM()
{
    memset(label_y, 0,sizeof(label_y));
    memset(match_y, -1,sizeof(match_y));
    for(int x = 0;x < n;x++)
    {
        label_x[x] = -INF;
        for(int y = 0;y < n;y++)
        {
            label_x[x] = max(label_x[x], g[x][y]);
        }
    }
    for(int x = 0;x < n;x++)
    {
        memset(slack_y, INF, sizeof(slack_y));
        while(true)
        {
            memset(visit_x, 0, sizeof(visit_x));
            memset(visit_y, 0, sizeof(visit_y));
            if(DFS(x))
                break;//找到增廣路所以離開
            int d = INF;
            for(int y = 0;y < n;y++)
            {
                if(!visit_y[y]) d = min(d, slack_y[y]);
            }
            //修改vertex labeling產生新的等邊
            for(int j = 0;j < n;j++)
            {
                if(visit_x[j])  label_x[j] -= d;
                if(visit_y[j])  label_y[j] += d;
                else    slack_y[j] -= d;
            } 
        }
    }
    int ans = 0;
    for(int y = 0;y < n;y++)
    {
        if(g[match_y[y]][y] != -INF)
            ans += g[match_y[y]][y];
    }
    return ans;
}

int main()
{
    
    return 0;
}
