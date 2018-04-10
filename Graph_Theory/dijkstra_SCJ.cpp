//BY SCJ
//tioj 1290
//dijkstra
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Edge{
    int to;
    long long cost;
};
bool operator < (Edge a,Edge b)
{
    return a.cost>b.cost;
}
const long long INF=1000000000000000;
long long d[1005];
int main()
{
    int n,m,st,ed;
    while(~scanf("%d%d%d%d",&n,&m,&st,&ed))
    {
        vector<Edge> G[1005];
        for(int i=1;i<=n;++i)   d[i]=INF;d[st]=0;
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back(Edge{b,c});
            G[b].push_back(Edge{a,c});
        }
        priority_queue<Edge> pq;
        pq.push(Edge{st,0});
        while(pq.size())
        {
            Edge t=pq.top();pq.pop();
            int v=t.to;
            if(d[v]<t.cost) continue;
            for(int i=0;i<G[v].size();++i)
            {
                Edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost)
                {
                    d[e.to]=d[v]+e.cost;
                    pq.push(Edge{e.to,d[e.to]});
                }
            }
        }
        if(d[ed]!=INF)  printf("%lld\n",d[ed]);     
        else puts("He is very hot");
    }
}
