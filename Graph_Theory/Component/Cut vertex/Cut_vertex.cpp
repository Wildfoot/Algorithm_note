/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

// Wrong Answer

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

// 維護兩個陣列
//  - dfn[u] = DFS traversal order
//      first visit time each vertex u in DFS
//  - low[u] = min(dfn[u], lowest low[v])
//      if edge (u,v) exist and v is not u’s parent

//  - Articulation?
//      if vertex u’s children can’t back to u’s ancestors
//      —> dfn[u] <= low[v], v is u’s child
//
//      if vertex u is root and has at least 2 child
//      —> count child >= 2
//
//  - Bridge?
//      two Articulation u, v
//      —> dfn[u] < low[v], v is u’s child

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

