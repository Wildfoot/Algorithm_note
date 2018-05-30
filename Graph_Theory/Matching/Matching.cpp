/* Matching
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

#include <iostream>
#include <ctime>

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
// Matching 匹配
// Matched Vertex 匹配點        和另一個點比翼雙飛
// Unmatched Vertex 未匹配點    孑然一身
// Matched Edge 匹配邊          出雙入對的兩點之間的邊
// Unmatched Edge 未匹配邊
//
// Cardinality 個數             一個匹配擁有的匹配邊數目
//      maximal matching：一張圖中，沒有辦法直接增加配對數的匹配。
//      maximum bipartite matching：一張二分圖的其中一個最大二分匹配。
//          Augmenting Path Algorithm
//          Hopcroft-Karp Algorithm
//
//      maximum matching：一張圖中，配對數最多的匹配。也是maximal matching。
//          Blossom Algorithm
//          Micali-Vazirani Algorithm
//
//      perfect matching：一張圖中，所有點都送作堆的匹配。也是maximum matching。
//
// Weight 權重                  一個匹配的權重是所有匹配邊的權重總和
//      maximum weight matching：一張圖中，權重最大的匹配。
//      maximum weight maximum cardinality matching：一張圖中，配對數最多的前提下，權重最大的匹配。
//      maximum weight perfect matching：一張圖中，所有點都送作堆的前提下，權重最大的匹配。
//          Blossom Algorithm
//
//      maximum weight perfect bipartite matching：一張二分圖的最大（小）權完美二分匹配。
//          Hungarian Algorithm
//          Kuhn-Munkres Algorithm
//

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

