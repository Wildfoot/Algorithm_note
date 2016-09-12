#include <iostream>
#define MAXN 100000

using namespace std;

struct Node
{
    Node *l, *r;
    int v;
    Node(){}
    Node(int v):v(v){l = r = nullptr;}
//    Node(Node *pt)
//    {
//        l = pt->l;
//        r = pt->r;
//        v = pt->v;
//    }
//    ~Node()
//    {
//        delete l;
//        delete r;
//    }
};

Node *Tnode[MAXN];

int main()
{
    Node Inode[MAXN];
    int N, Q;
    cin >> N >> Q;
    for(int i = 0;i < N;i++)
    {
        Tnode[i] = *Inode[i];

    }
    while(Q--)
    {

    }
    return 0;
}
