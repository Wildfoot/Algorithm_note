#include <iostream>
#define maxn 1000

int lch[maxn], rch[maxn];   //每個結點的左右子節點
char op[maxn];      //每個節點的字元
int nc = 0;     //節點數


using namespace std;

int build_tree(string s, int x, int y)
{
    int c1 = -1, c2 = -1, p = 0;
    int u;                          //自身節點編號

    if(y - x == 1)      //僅一個字元 建立單獨節點
    {
        u = ++nc;
        lch[u] = 0;     //沒有子節點
        rch[u] = 0;
        op[u] = s[x];
        cout << s[x] << "op[" << u << "]" << " ";
        return u;
    }

    for(int i = x;i < y;i++)
    {
        switch(s[i])
        {
            case '(': 
                p++;
                break;
            case ')':
                p--;
                break;
            case '+': case '-':         
                if(!p)                  //如果不在括號內
                    c1 = i;             //最後一個加或減字元位置
                break;
            case '*': case '/':
                if(!p)                  
                    c2 = i;             //最後一個乘或除字元位置
                break;
        }
    }

    if(c1 < 0)          //找不到括號外的加減號
    {
        c1 = c2;   
        if(c1 < 0)          //整個運算式最外為一對括號
            return build_tree(s, x + 1, y - 1);
    }
    u = ++nc;
    lch[u] = build_tree(s, x, c1);
    rch[u] = build_tree(s, c1 + 1, y);
    op[u] = s[c1];
    return u;
}

int main()
{
    string s = "a+b*(c-d)-e/f";
    build_tree(s, 0, 13);
    cout << endl;
    for(int i = 0;i < 12;i++)
        cout << op[i] << " ";
    return 0;
}
