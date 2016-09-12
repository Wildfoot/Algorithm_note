int find(int n)
{
    if(father[n] == n)return n;
    father[n] = find(father[n]); //優化father[n] -> 最後的father
    return father[n];
}

int U(int a,int b)//融合兩個圖
{
    //優化：將小的接到大的 O(alpha(n))  約等於  O(1)
    //記路圖大小
    father[find(a)] = find(b)
}
