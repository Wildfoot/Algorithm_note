/* Kosaraju
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAXN 10000

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

static vector<int> edges_obverse[MAXN];
static vector<int> edges_reverse[MAXN];
static stack<int> finish_point;
static node nodes[MAXN];

void clear_node_visit(int node_num)
{
    for(int i = 0;i < node_num;i++)
    {
        nodes[i].visit = false;
    }
}

void print_node(int node_num)
{
    for(int i = 0;i < node_num;i++)
    {
        cout << "node " << i << ": ";
        cout << nodes[i].SCC_index << endl;
    }
}

void initial(int node_num)
{
    clear_node_visit(node_num);
    for(int i = 0;i < node_num;i++)
    {
        edges_obverse[i].clear();
        edges_reverse[i].clear();
    }
    return;
}

void DFS_first(int node_no)
{
    nodes[node_no].visit = true;
    for(int e:edges_obverse[node_no])
    {
        if(!nodes[e].visit)
        {
            DFS_first(e);
        }
    }
    finish_point.push(node_no);
    return;
}

void DFS_second(int node_no, const int &cSCC_index)
{
    nodes[node_no].SCC_index = cSCC_index;
    nodes[node_no].visit = true;
    for(int e:edges_reverse[node_no])
    {
        if(!nodes[e].visit)
        {
            DFS_second(e, cSCC_index);
        }
    }
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

        initial(node_num);

        for(int i = 0;i < edge_num;i++)
        {
            int input_from, input_to;
            cout << "from, to: ";
            cin >> input_from >> input_to;
            edges_obverse[input_from].push_back(input_to);
            edges_reverse[input_to].push_back(input_from);
        }

        //first DFS -> put the finish node in stack
        for(int i = 0;i < node_num;i++)
        {
            if(!nodes[i].visit)
            {
                DFS_first(i);
            }
        }

        clear_node_visit(node_num);

        // second DFS -> process the reverse DFS and mark the SCC index.
        int current_SCC_index = 0;
        while(!finish_point.empty())
        {
            int current_node = finish_point.top();
            finish_point.pop();
            if(!nodes[current_node].visit)
            {
                DFS_second(current_node, current_SCC_index);
                current_SCC_index++;
            }
        }

        print_node(node_num);
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

