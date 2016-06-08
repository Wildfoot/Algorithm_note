#include <iostream>
#include <cstring>

using namespace std;


bool adj[9][9];
int visit[9], parent[9], low[9], t = 0;
 
void DFS(int i)
{
    visit[i] = low[i] = ++t;
 
    for (int j=0; j<9; ++j)
        if (adj[i][j])
            if (!visit[j])
            {
                parent[j] = i;
                DFS(i);
                low[i] = min(low[i], low[j]);
            }
            else if (j != parent[i])
                low[i] = min(low[i], visit[j]);
}
 
void articulation_vertex()
{
    // DFS forest
    memset(visit, 0, sizeof(visit));
    t = 0;
 
    for (int i=0; i<9; ++i)
        if (!visit[i])
        {
            parent[i] = i;  // i is root;
            DFS(i);
        }
 
    // 尋找所有關節點
    for (int i=0; i<9; ++i)
        if (i == parent[i]) // root
        {
            int child = 0;
            for (int j=0; j<9; ++j)
                if (parent[j] == i && j != i)
                    child++;
 
            if (child > 1)
                cout << "articulation vertex" << i;
        }
        else
        {
            bool ap = false;
            for (int j=0; j<9; ++j)
                if (parent[j] == i && low[j] >= visit[i])
                    ap = true;
 
            if (ap)
                cout << "articulation vertex" << i;
        }
}

int main()
{
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[1][3] = 1;
    adj[3][4] = 1;
    adj[0][4] = 1;
    adj[0][5] = 1;
    adj[5][6] = 1;
    adj[6][7] = 1;
    adj[5][7] = 1;
    adj[7][8] = 1;
    adj[7][9] = 1;
    adj[1][0] = 1;
    adj[2][1] = 1;
    adj[3][1] = 1;
    adj[4][3] = 1;
    adj[4][0] = 1;
    adj[5][0] = 1;
    adj[6][5] = 1;
    adj[7][6] = 1;
    adj[7][5] = 1;
    adj[8][7] = 1;
    adj[9][7] = 1;
    articulation_vertex();
    return 0;
}
