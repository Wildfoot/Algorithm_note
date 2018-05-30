/* Augmenting Path algorithm - maximum bipartite matching
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <array>

#define INF 2147483647
#define EPS 1e-9
#define DEFAULT_FIXSTR 3

using namespace std;

inline string _fixstr(string para, int alignment_num = DEFAULT_FIXSTR)
{
    para.resize(alignment_num, ' ');
    return para;
}
inline string _fixstr(char para, int alignment_num = DEFAULT_FIXSTR)
{
    string ret = string(1, para);
    return _fixstr(ret, alignment_num);
}
inline string _fixstr(int para, int alignment_num = DEFAULT_FIXSTR)
{
    string ret = to_string(para);
    if(para == INF)
        ret = "INF";
    return _fixstr(ret, alignment_num);
}

// 1. 枚舉左邊這群的每個點，嘗試找尋augmenting path
// 2. 每次找到augmenting path，對調匹配與未匹配邊
/* code start here */
class Bipartite
{
private:
    bool * visited; // for DFS;
    void _Bipartite_DFS(int current, bool is_left)
    {
        visited[current] = true;
        vector<int> & current_node = nodes[current];
        if(is_left)
            left_side.push_back(&current_node);
        else
            right_side.push_back(&current_node);

        for(int e:current_node)
        {
            if(!visited[e])
            {
                _Bipartite_DFS(e, ~is_left);
            }
        }
    }
protected:
    int node_num, edge_num;
    vector<int> * nodes;
    vector<vector<int>*> left_side, right_side;
public:
    Bipartite(int node_num):
        node_num(node_num)
    {
        edge_num = 0;
        nodes = new vector<int>[node_num];
        visited = new bool[node_num];
    }
    ~Bipartite()
    {
        delete[] nodes;
        delete[] visited;
    }
    void add_edge(int A, int B)
    {
        nodes[A].push_back(B);
        nodes[B].push_back(A);
    }
    void create_bipartite_graph()
    {
        for(int i = 0;i < node_num;i++)
            visited[i] = false;
        _Bipartite_DFS(0, true);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

