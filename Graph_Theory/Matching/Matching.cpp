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
// Alternating Path 交錯路徑
// Alternating Cycle 交錯環
// Augmenting Path 擴充路徑     第一個點和最後一個點都是未匹配點的一條交錯路徑
//
// Augmenting Path Theorem
//      從圖上任取一個未匹配點，如果找不到以此點作為端點的擴充路徑，那麼這張圖會有一些最大匹配不會包含此點。更進一步來說，就算從這張圖上刪除此點（以及相連的邊），以剩餘的點和邊，還是可以找到原本那張圖的其中一些最大匹配。
// 找最大匹配的手段：
//      1. 一開始圖上所有點都是未匹配點。
//      2. 將圖上每一個未匹配點都嘗試作為擴充路徑的端點：
//      　甲、如果找得到擴充路徑：
//      　　　沿著擴充路徑修改現有匹配，以增加Cardinality。
//      　　　（此未匹配點變成了匹配點。）
//      　乙、如果找不到擴充路徑：
//      　　　直接刪除此點。繼續下去仍然可以找到原圖的其中一個最大匹配。
//      　　　（此未匹配點被刪除。）
//

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

