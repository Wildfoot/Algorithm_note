#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

#define MAXN 10 //MAX node + 1
#define MAXE 11 //MAX edge + 1

using namespace std;

bool used[MAXN];
vector<int> V[MAXN];
int level_t;
int level[MAXN];
int son_grand[MAXN]; //n的子孫能連到的最高 + 自己如果有連到祖父以上
bool ap[MAXE];
int ap_ptr;

void DFS(int n, int g) //g是父親
{
    level[n] = level_t;
    son_grand[n] = level[n]; //預設自己
    used[n] = 1;
    int child = 0;


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

        cout << "son_grand[ "<< n <<" ] = " << son_grand[n] << " son_grand[ "<< e <<" ] = " << son_grand[e] << " ap_ptr = " << ap_ptr << " ";
        if(son_grand[n] == son_grand[e])
        {
            cout << n << " " << e;
            ap[ap_ptr] = 1;
        }
        ap_ptr++;
        cout << endl;

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
    memset(ap, 0, sizeof(ap));
    level_t = 1;
    ap_ptr = 0;
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
    
    for(int i = 0;i < MAXE;i++)
        cout << ap[i] << " ";
    cout << endl;
    return 0;
}
