#include <iostream>
#include <vector>
#include <cstring>
#define MAXN_1 505
#define MAXN_2 505

using namespace std;

int n1, n2;
int match[MAXN_2]; //每個n2裡的點匹配到哪裡

vector<int> g[MAXN_1];
bool visit[MAXN_2];

bool DFS(int u)
{
    for(int v:g[u])
    {
        if(visit[v])
            continue;
        visit[v] = 1;
        if(match[v] == -1 || DFS(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}
inline int max_match()
{
    int ans = 0;
    memset(match, -1, sizeof(int) * n2);
    for(int i = 0;i < n1;i++)
    {
        memset(visit, 0, sizeof(bool) * n2);
        if(DFS(i))
            ans++;
    }
    return ans;
}


int main()
{
    cin >> n1 >> n2;
    int m;
    cin >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ANS = max_match();
    cout << ANS << endl;
    return 0;
}
