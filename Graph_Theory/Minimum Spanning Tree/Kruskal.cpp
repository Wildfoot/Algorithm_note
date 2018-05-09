/* Kruskal
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <iostream>
#include <ctime>
#include <queue>
#include <vector>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 10000

static int father[MAX];
int find(int n)
{
    if(father[n] == n)
        return n;
    father[n] = find(father[n]);
    return father[n];
}
inline int union_set(int a, int b)
{
    father[find(a)] = find(b);
}

class edge
{
    public:
        int u, v;
        int cost;
        edge(int input_u, int input_v, int input_cost):
            u(input_u), v(input_v), cost(input_cost)
        {
        }
};

struct custom_compare
{
    bool operator()(edge &lhs, edge &rhs)
    {
        return lhs.cost > rhs.cost;
    }
};

template <class T>
void print_container_top(T qu)
{
    while(!qu.empty())
    {
        clog << qu.top().u << " " << qu.top().v << " " << qu.top().cost << endl;
        qu.pop();
    }
}
template <class T>
void print_container_front(T qu)
{
    while(!qu.empty())
    {
        clog << qu.front().u << " " << qu.front().v << " " << qu.front().cost << endl;
        qu.pop();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true)
    {
        int node_num, edge_num;
        cin >> node_num >> edge_num;
        if(!node_num && !edge_num)
            break;

        for(int i = 0;i < node_num;i++)
        {
            father[i] = i;
        }
        priority_queue<edge, vector<edge>, custom_compare> pq;

        for(int i = 0;i < edge_num;i++)
        {
            int input_u, input_v, input_cost;
            cin >> input_u >> input_v >> input_cost;
            pq.push(edge{--input_u, --input_v, input_cost});
        }
        //print_container_top(pq);

        queue<edge> ans_qu;
        int min_ans = 0;

        while(!pq.empty())
        {
            edge cedge = pq.top();
            pq.pop();
            if(find(cedge.u) != find(cedge.v))
            {
                union_set(cedge.u, cedge.v);
                ans_qu.push(cedge);
                min_ans += cedge.cost;
            }
        }

        cout << "minimun cost: " << min_ans << endl;
        print_container_front(ans_qu);
    }


    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

