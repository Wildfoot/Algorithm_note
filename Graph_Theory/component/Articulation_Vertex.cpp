#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

#define MAXN 10 //MAX node + 1

using namespace std;

bool used[MAXN];
vector<int> V[MAXN];
int level_t;
int level[MAXN];
int son_grand[MAXN]; //n的子孫能連到的最高 + 自己如果有連到祖父以上
bool ap[MAXN];

void DFS(int n, int g) //g是父親
{
    level[n] = level_t;
    son_grand[n] = level[n]; //預設自己
    //cout << "n = " << n << " level[n] = " << level[n] << endl;
    used[n] = 1;
    int child = 0;
    ap[n] = false;


    for(int e:V[n])
    {
        if(e == g)          //避免回頭路
            continue;

        level_t++;
        if(!used[e])
        {
            child++;
            DFS(e, n);
        }
        
        if(son_grand[e] < son_grand[n])
        {
            son_grand[n] = son_grand[e];
        }

        if(son_grand[e] >= level[n])  //有任何一個小孩的son_grand大於自己本身的level(沒有環)
            ap[n] = true;

        level_t--;
    }

    cout << "n = " << n << " level[n] = " << level[n] << " child = " << child << " son_grand[n] = " << son_grand[n] << endl;


    if(level[n] == 1) //判斷根是否有兩個兒子
    {
        ap[n] = false;
        if(!(child == 1))
            ap[n] = true;
    }
}

void articulation_vertex()
{
    memset(level, 0, sizeof(level));
    memset(used, 0, sizeof(used));
    level_t = 1;
    DFS(0, 0);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    articulation_vertex();
    
    for(int i = 0;i < MAXN;i++)
        cout << ap[i] << " ";
    cout << endl;
    return 0;
}
