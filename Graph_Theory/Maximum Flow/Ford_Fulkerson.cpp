/* Ford-Fulkerson
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 * Node No.  input-1~N  code-0~N-1
 */

#include <iostream>
#include <ctime>
#include <cstring>

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

/* code start here */

class Ford_Fulkerson
{
private:
    bool * _visited;  //for DFS
    int * _parent;
    bool _DFS_Recursion(int current_node)   //DFS Residual Network
    {
        _visited[current_node] = true;
        if(current_node == sink)
            return true;
        for(int i = 0;i < node_num;i++)
        {
            if(_visited[i])
                continue;
            if(capacity[current_node][i] - flow[current_node][i] > 0 || flow[i][current_node] > 0)  //正流or把原本流的抵消
            {
                _parent[i] = current_node;
                if(_DFS_Recursion(i))
                    return true;
            }
        }
        return false;
    }
    void _print_pipe_status()
    {
        clog << "==== capacity ====" << endl;
        for(int i = 0;i < node_num;i++)
        {
            for(int j = 0;j < node_num;j++)
            {
                clog << _fixstr(capacity[i][j]);
            }
            clog << endl;
        }
        clog << "====== flow ======" << endl;
        for(int i = 0;i < node_num;i++)
        {
            for(int j = 0;j < node_num;j++)
            {
                clog << _fixstr(flow[i][j]);
            }
            clog << endl;
        }
        clog << "==== Residual ====" << endl;
        for(int i = 0;i < node_num;i++)
        {
            for(int j = 0;j < node_num;j++)
            {
                clog << _fixstr(capacity[i][j] - flow[i][j]);
            }
            clog << endl;
        }
    }

protected:
    int node_num, pipe_num;
    int source, sink;
    int ** capacity, ** flow; //record the 2D graph
    bool Depth_First_Search()   //DFS init and process
    {
        memset(_visited, false, node_num);
        return _DFS_Recursion(source);
    }
    int find_bottleneck()
    {
        int bottle_neck = INF;
        for(int i = sink, pre;i != source;i = pre) //find bottle neck
        {
            pre = _parent[i];
            if(capacity[pre][i] - flow[pre][i] > 0)
                bottle_neck = min(bottle_neck, capacity[pre][i] - flow[pre][i]);
            else
                bottle_neck = min(bottle_neck, flow[i][pre]);
        }
        for(int i = sink, pre;i != source;i = pre) //update flow array
        {
            pre = _parent[i];
            if(capacity[pre][i] - flow[pre][i] > 0)
                flow[pre][i] += bottle_neck;
            else
                flow[i][pre] -= bottle_neck;
        }
        return bottle_neck;
    }

public:
    Ford_Fulkerson(int node_num, int pipe_num):
        node_num(node_num), pipe_num(pipe_num)
    {
        _visited = new bool[node_num];
        _parent = new int[node_num];
        capacity = new int*[node_num];
        flow = new int*[node_num];
        for(int i = 0;i < node_num;i++)
        {
            capacity[i] = new int[node_num];
            flow[i] = new int[node_num];
        }
        for(int i = 0;i < node_num;i++)
        {
            for(int j = 0;j < node_num;j++)
            {
                capacity[i][j] = 0;
                flow[i][j] = 0;
            }
        }
    }
    ~Ford_Fulkerson()
    {
        delete[] _visited;
        delete[] _parent;
        for(int i = 0;i < node_num;i++)
        {
            delete[] capacity[i];
            delete[] flow[i];
        }
        delete[] capacity;
        delete[] flow;
    }
    void set_ST(int start, int target)
    {
        source = start;
        sink = target;
    }
    void add_pipe(int from, int to, int cap)
    {
        capacity[from][to] += cap;
    }
    int process()   //main function of ford fulkerson
    {
        int ret = 0;
        while(true)
        {
            //_print_pipe_status();   //DEBUG
            if(!Depth_First_Search())
                break;
            ret += find_bottleneck();
        }
        return ret;
    }
};

class Multi_ST_Ford_Fulkerson: public Ford_Fulkerson
{
protected:
    int origin_node_num, origin_pipe_num;
    int source_node_num, sink_node_num;
    int super_source_node, super_sink_node;
public:
    Multi_ST_Ford_Fulkerson(int origin_node_num, int origin_pipe_num):
        origin_node_num(origin_node_num), origin_pipe_num(origin_pipe_num), Ford_Fulkerson(origin_node_num + 2, origin_pipe_num)  //pipe num is not correct yet
    {
        set_ST(super_source_node = origin_node_num, super_sink_node = origin_node_num + 1);     //super source(N) and sink(N + 1) node
        source_node_num = 0;
        sink_node_num = 0;
    }
    void add_source_node(int node_no)
    {
        source_node_num++;
        pipe_num++;
        add_pipe(super_source_node, node_no, INF);
    }
    void add_sink_node(int node_no)
    {
        sink_node_num++;
        pipe_num++;
        add_pipe(node_no, super_sink_node, INF);
    }
};

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int node_num, pipe_num;
    while(cin >> node_num >> pipe_num)
    {
        if(!node_num && !pipe_num)
            break;
        int source, sink;
        cin >> source >> sink;

        Ford_Fulkerson Test{node_num, pipe_num};
        Test.set_ST(--source, --sink);

        for(int i = 0;i < pipe_num;i++)
        {
            int from, to, capacity;
            cin >> from >> to >> capacity;
            Test.add_pipe(--from, --to, capacity);
        }
        int answer = Test.process();
        cout << answer << endl;
    }

    while(cin >> node_num >> pipe_num)// multi-source and multi-sink
    {
        if(!node_num && !pipe_num)
            break;

        Multi_ST_Ford_Fulkerson Test{node_num, pipe_num};

        int source_num, sink_num;

        cin >> source_num;
        for(int i = 0;i < source_num;i++)
        {
            int node_no;
            cin >> node_no;
            Test.add_source_node(--node_no);
        }
        cin >> sink_num;
        for(int i = 0;i < sink_num;i++)
        {
            int node_no;
            cin >> node_no;
            Test.add_sink_node(--node_no);
        }
        for(int i = 0;i < pipe_num;i++)
        {
            int from, to, capacity;
            cin >> from >> to >> capacity;
            Test.add_pipe(--from, --to, capacity);
        }
        int answer = Test.process();
        cout << answer << endl;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

