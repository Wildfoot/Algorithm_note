#include <iostream>

using namespace std;

int array[1 << 9];    // 數列
 
struct Node
{
//  int L, R;   // 其下所有樹葉的數列索引值範圍
    int sum;    // 其下所有樹葉的區間總和
//  int min;    // 其下所有樹葉的區間最小值
//  int max;    // 其下所有樹葉的區間最大值
} node[1<<10];  // 用陣列模擬二元樹
 
// 用陣列模擬二元樹：左小孩、右小孩
int LC(int i) {return i*2;}
int RC(int i) {return i*2+1;}
 
//int sum[1<<10];   // 更簡便的寫法
 
void build(int L, int R, int i)
{
    if (L == R)
    {
        // 設定樹葉的數值
        node[i].sum = array[L];
        return;
    }
 
    int M = (L + R) / 2;
    build(L  , M, LC(i));   // 遞迴建立左子樹
    build(M+1, R, RC(i));   // 遞迴建立右子樹
 
    // 回溯時順便計算總和
    node[i].sum = node[LC(i)].sum + node[RC(i)].sum;
}
 
int x, n;   // 更新位置、數值大小
void update(int L, int R, int i)
{
    if (L == R)
    {
        node[i].sum = n;
        return;
    }
 
    int M = (L + R) / 2;
    if (x <= M) update(L  , M, LC(i));  // 遞迴更新左子樹
    if (x >  M) update(M+1, R, RC(i));  // 遞迴更新右子樹
 
    // 回溯時順便更新總和
    node[i].sum = node[LC(i)].sum + node[RC(i)].sum;
}
 
int x1, x2, total;  // 查詢範圍[x1,x2]並且累計總和
void query(int L, int R, int i)
{
    if (x1 <= L && R <= x2)
    {
        total += node[i].sum;
        return;
    }
 
    int M = (L + R) / 2;
    if (x1 <= M) query(L  , M, LC(i));  // 遞迴查詢左子樹
    if (x2 >  M) query(M+1, R, RC(i));  // 遞迴查詢右子樹
}
 
void demo()
{
    // 建立索引值0到99的偽線段樹。
    for (int i=0; i<100; ++i) cin >> array[i];
    build(0, 99, 1);
 
    // 索引值為5的元素，更新為7。
    x = 5; n = 7;
    update(0, 99, 1);
 
    // 查詢區間[3,3]的總和。
    x1 = 3; x2 = 3; total = 0;
    query(0, 99, 1);
    cout << total;
}
int main()
{
    for (int i=0; i<100; ++i) cin >> array[i];
    build(0, 99, 1);
    return 0;
}
