//尋找一張無向圖上所有的 Articulation Vertex
//時間複雜度等於一次 DFS 的時間。
//圖的資料結構為 adjacency matrix ，便是 O(V^2)
//圖的資料結構為 adjacency lists ，便是 O(V+E)

#include <iostream>
#include <cstring>
#define MAXN 9

using namespace std;

bool adj[9][9]; // 無向圖，adjacency matrix。
int visit[9];   // DFS遍歷順序，用來判斷祖先與子孫。
int grand[9];   // 紀錄該點的子孫們用back edge連到的最高祖先。
                // 例如第4點的子孫們，
                // 有back edge連到祖先第grand[4]點。
int t = 0;      // 時刻。
 
void DFS(int p, int i)  // 第p點是第i點的父親
{
    visit[i] = ++t;     // 紀錄遍歷順序
    grand[i] = i;       // 預設為沒找到back edge
 
    int child = 0;      // 紀錄第i點有幾個小孩
    bool ap = false;    // 紀錄第i點是不是關節點
 
    for (int j=0; j<9; ++j)         // 進行DFS
        if (adj[i][j] && j != p)    // 避免回頭路
            if (visit[j])           // back edge
            {
                // 紀錄最高的祖先。
                if (visit[j] < visit[grand[i]])
                    grand[i] = j;
            }
            else                    // tree edge
            {
                child++;
                DFS(i, j);
 
                // 紀錄第i點的子孫們，利用back edge連到的最高祖先。
                if (visit[grand[i]] < visit[grand[j]])
                    grand[i] = grand[j];
 
                // 第i點的祖先、第i點的其中一棵子樹（樹根為第j點）
                // 兩者之間缺少back edge，因此第i點為關節點。
                if (visit[grand[j]] >= visit[i])
                    ap = true;
            }
 
    // 判斷是不是關節點。樹根和非樹根分開判斷。
    if (i == p && child > 1 || i != p && ap)
        cout << "第" << i << "點是關節點" << endl;
}
 
void articulation_vertex()
{
    // DFS forest
    memset(visit, 0, sizeof(visit));
    t = 0;
 
    for (int i=0; i<9; ++i)
        if (!visit[i])
            DFS(i, i);
    
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
