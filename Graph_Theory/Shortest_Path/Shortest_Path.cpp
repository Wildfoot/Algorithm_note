// 
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

// Single Source Shortest Path
// 給定起點，求出起點到圖上每一點的最短路徑。一對全。
// 重要觀念 - Relaxation
//     先找一條路徑 再找有沒有更短的 並記住最短的
// - Bellman Ford
// O(VE)
//     relax all edges in graph
//     totally n-1 times (跑過所有的邊n-1次)
//     Stop when all edges stop relaxing
//     - Negative Cycle?
//         如果跑過n-1次還有relax出現 代表有負環(全圖)
//
// - SPFA
// O(kE) average: k << V
//     Only relax the once whose cost changed(use queue)
//     - Negative Cycle?
//         Count the times of pushing a node in queue.
//         如果超過n-1次 代表有負環在路徑上
//
// - Dijkstra
//     SPFA + priority queue
//     struct edge{int to, cost}
//     priority queue 由小到大排序, queue放入起點{start, 0}
//     1. 從queue中取出一點a, 點a必須是不在最短路徑上的點
//     2. 如果點a更新, 將與a點相連的edge加入queue
//
// All Pair Shortest Path
// 求出圖上所有兩點之間的最短路徑。全對全。
// - Floyd
// O(V ^ 3)
//   set the value between node i, j (if exist)
//   and process all k between i and j to find if shorter
//   i ======> j
//   i => k => j
//
//     Floyd(){
//       dis[i][j] = 0, for i=j
//       dis[i][j] = w(i, j), for each edge w(i, j)
//       dis[i][j] = INF, otherwise.
//       for(k = 0;k < n;k++)
//          for(i = 0;i < n;i++)
//              for(j = 0;j < n;j++)
//                  if(dis[i][j] + dis[k][j] < dis[i][j])
//                      dis[i][j] = dis[i][k] + dis[k][j];
//     }
//
// - Dijkstra * V times
// - SPFA * V times(sometimes better than Floyd)
//
////////////////////// output the solution ////////////////////////
// - Record the previous one
//     Once relax successfully, update prev[id]
//

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

