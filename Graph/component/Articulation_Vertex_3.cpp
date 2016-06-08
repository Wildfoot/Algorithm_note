#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

#define MAXN 9 //MAX node 

using namespace std;

//bool used[MAXN];
vector<int> V[MAXN];
int level_t;
int level[MAXN];

void DFS(int n)
{
    level[n] = level_t;
    cout << n << " " << level[n] << endl;
    for(int e:V[n])
    {
        level_t++;
        if(!level[e])
        {
            DFS(e);
        }
        level_t--;
        cout << "DFS done" << endl;
    }

}

void articulation_vertex()
{
    memset(level, 0, sizeof(level));
    level_t = 1;
    //for()
        //if(!)
            DFS(0);
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
    //DFS(0);
    
    return 0;
}
