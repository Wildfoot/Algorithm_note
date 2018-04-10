#include <iostream>
#include <queue>
#include <vector>
#define INF 2147364748

using namespace std;

struct Edge{
    int to;
    long long cost;
};

bool operator < (Edge a, Edge b)
{
    return a.cost > b.cost;  //priorityq isfrom big to small
}

long long d[1001]; //存在點上的 目前到這點最短的距離

int main()
{
    cin.tie(0);
    int n, m, st, ed; 
    while(cin >> n >> m >> st >> ed)
    {
        //initial
        vector<Edge> G[1005];
        for(int i = 1;i <= n;i++)
            d[i] = INF; 
        d[st] = 0;

        for(int i = 0;i < m;i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Edge{b, c});
            G[b].push_back(Edge{a, c});
        }
        priority_queue<Edge> pq;
        pq.push(Edge{st, 0});

        while(pq.size())
        {
            Edge t = pq.top();
            pq.pop();
            int v = t.to;
            if(d[v] < t.cost)
                continue;
            for(int i = 0;i < G[v];i++)
            {
                Edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    pq.push(Edge{e.to, d[e.to]});
                }
            }
        }
        if(d[ed] != INF)
            cout << d[ed];
        else
            cout << "He is very hot";
    }
    return 0;
}
