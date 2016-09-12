//By SCJ
//求最小權重
#include<bits/stdc++.h>
using namespace std;
#define maxn 10005//題目給定點的範圍
#define maxm 500005//題目給定邊的範圍
int n,m;//n-> 點的數量  m->邊的數量
struct Edge{
    int u,v,cost;//u,v為這個邊的兩個端點，cost為該邊的權重
}es[maxm];//所有的邊
bool cmp(Edge a,Edge b)//以邊的權重做排序
{
    return a.cost<b.cost;
}
int pa[maxn];//紀錄每個點的上一代祖先是誰
int find(int x)//尋找祖先
{
    if(pa[x]==x) return x;//發現自己就是這個集合的祖先(樹根)，並return 自己。
    return pa[x]=find(pa[x]);
    //return 這個集合的祖先(樹根)，並把自己連去樹根(這非常重要)。
    //若只有寫return find(pa[x]);複雜度會爛掉
}
void U(int x,int y)//將兩個集合合併
{
    pa[find(x)]=find(y);//將x的祖先連到y的祖先
    //切記不可寫成pa[x]=y;
}
int kruskal()
{
    int ans=0;
    for(int i=0;i<n;++i) pa[i]=i;//將每個點的祖先預設為自己
    sort(es,es+m,cmp);
    for(int i=0;i<m;++i)
    {
        Edge e=es[i];
        if(find(e.u)!=find(e.v))//若兩點在不同的集合則合併
        {
            U(e.u,e.v);
            ans+=e.cost;//把答案加上該邊的cost
        }
    }
    for(int i=1;i<n;++i) if(find(i)!=find(i-1)) return -1;//若有任兩個點不再同一個集合則代表不存在MST
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>es[i].u>>es[i].v>>es[i].cost;
    }
    cout<<kruskal()<<'\n';
}
