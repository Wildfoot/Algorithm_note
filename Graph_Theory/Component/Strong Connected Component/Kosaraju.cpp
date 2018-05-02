/* Kosaraju
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

// Wrong Answer

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

class node
{
    public:
        int SCC_index;
        bool visit;
        node(void):
        visit(false)
        {
        }
};

void DFS_first(int n, vector<int> * edges, node * nodes, stack<int> & finish_point)
{
    nodes[n].visit = true;
    for(int e:edges[n])
    {
        if(!nodes[e].visit)
            DFS_first(e, edges, nodes, finish_point);
    }
    finish_point.push(n);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true)
    {
        int node_num, edge_num;

        cout << "amount of node, edge: ";
        cin >> node_num >> edge_num;
        if(!node_num && !edge_num)
            break;

        vector<int> edges = new vector<int> [node_num];
        vector<int> edges_reverse = new vector<int> [node_num];
        stack<int> finish_point;
        node * nodes = new node [node_num];

        for(int i = 0;i < edge_num;i++)
        {
            int input_from, input_to;
            cout << "from, to: ";
            cin >> input_from >> input_to;
            edges[input_from].push_back(input_to);
            edges_reverse[input_to].push_back(input_from);
        }

        for(int i = 0;i < node_num;i++)
        {
            if(!nodes[i].visit)
                DFS_first(i, edges, nodes, finish_point);
        }

        delete [] edges;
        delete [] edges_reverse;
        delete [] nodes;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

