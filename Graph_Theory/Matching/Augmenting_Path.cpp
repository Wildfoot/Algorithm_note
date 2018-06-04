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
#include <set>

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

// 1. 枚舉左（右）邊這群的每個點，嘗試找尋augmenting path
// 2. 每次找到augmenting path，對調匹配與未匹配邊
/* code start here */
class normal_vector_graph
{
protected:
    int node_num, edge_num;
    vector<int> * nodes;
public:
    normal_vector_graph(int node_num):
        node_num(node_num)
    {
        edge_num = 0;
        nodes = new vector<int>[node_num];
    }
    ~normal_vector_graph()
    {
        delete[] nodes;
    }
    void add_edge(int A, int B)
    {
        edge_num++;
        nodes[A].push_back(B);
        nodes[B].push_back(A);
    }
};
class Bipartite: public normal_vector_graph
{
private:
    bool * _visited; // for DFS;
    void _Bipartite_DFS(int current, bool is_left)
    {
        _visited[current] = true;
        vector<int> & current_node = nodes[current];
        if(is_left)
            left_side.insert(current);
        else
            right_side.insert(current);

        for(int e:current_node)
        {
            if(!_visited[e])
            {
                _Bipartite_DFS(e, !is_left);
            }
        }
    }
protected:
    set<int> left_side, right_side;
public:
    Bipartite(int node_num):
        normal_vector_graph(node_num)
    {
        _visited = new bool[node_num];
    }
    ~Bipartite()
    {
        delete[] _visited;
    }
    void create_bipartite_graph()
    {
        for(int i = 0;i < node_num;i++)
            _visited[i] = false;
        for(int i = 0;i < node_num;i++)
        {
            if(!_visited[i])
                _Bipartite_DFS(i, true);
        }
    }
    void _print_bipartite() //DEBUG
    {
        clog << "node at left side:" << endl;
        for(int e:left_side)
            clog << e << " ";
        clog << endl;
        clog << "node at right side:" << endl;
        for(int e:right_side)
            clog << e << " ";
        clog << endl;
    }
};
class Augmenting_Path: public Bipartite
{
private:
    bool * _visited;
    bool * _is_matched;
    bool _DFS(int current_node)
    {
        _visited[current_node] = true;
        for(int e:nodes[current_node])
        {
            if(!_visited[e])
            {
                //e unmatched and is left
                if(!_is_matched[e] && left_side.find(e) != left_side.end())
                {
                    _is_matched[e] = true;
                    return true;
                }
                if(_DFS(e))
                {
                    return true;
                }
            }
        }
        return false;
    }
protected:
public:
    Augmenting_Path(int node_num):
        Bipartite(node_num)
    {
        _visited = new bool[node_num];
        _is_matched = new bool[node_num];
    }
    int calculate_maximum_cardinality_match()
    {
        int matched_edge_num = 0;
        for(int i = 0;i < node_num;i++)
        {
            _is_matched[i] = false;
        }
        for(int e:right_side)
        {
            if(!_is_matched[e])
            {
                for(int i = 0;i < node_num;i++)
                {
                    _visited[i] = false;
                }
                if(_DFS(e))
                {
                    _is_matched[e] = true;
                    matched_edge_num++;
                }
            }
        }
        return matched_edge_num;
    }
    void _print_matched()
    {
        for(int i = 0;i < node_num;i++)
        {
            cout << "_is_matched[" << i << "] = " << _is_matched[i] << endl;
        }
    }
};

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int node_num, edge_num;
    while(cin >> node_num >> edge_num)
    {
        if(!node_num && !edge_num)
            break;

        //Bipartite test{node_num};
        Augmenting_Path test{node_num};
        int ans;

        for(int i = 0;i < edge_num;i++)
        {
            int node_a, node_b;
            cin >> node_a >> node_b;
            test.add_edge(node_a, node_b);
        }
        test.create_bipartite_graph();
        test._print_bipartite(); //DEBUG
        ans = test.calculate_maximum_cardinality_match();
        test._print_matched();
        cout << "maximum cardinality match: " << ans << endl;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

