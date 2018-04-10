//TOJ 31
//UVa 11922
//UVa 12538
//UVa 1479
//隨機二叉樹
//  平衡樹
//  • 平衡樹滿足其中序是順序性的序列
//  • STL set、map不夠用?(問第k大元素)
//  • 需要分裂合併
//變態操作 線段樹無法解
//伸展樹難寫常樹大
//
//  隨機二叉樹
//      只需要利用節點大小作為平衡因子
//      利用隨機平衡
//      可持久化(很重要)
struct node
{
    node *l,*r;     //指向左右子樹的指標
    int size;       //以這個節點為根的子樹其結點個數（大小）
    int key;        //儲存的資訊
    node(int k):l(0),r(0),size(1) ,key(k){}
    inline void up()//更新size和的懶惰標記
    {
        size=1;
        if(l)size+=l->size;
        if(r)size+=r->size;
    }
    inline void down()//更新size和的懶惰標記
    {
        //懶惰標記下推
    }
};
//split
//• 過程可以簡述成三個問句:
//1.做完了嗎?
//2.根要送誰?
//3.哪邊還沒做完?
void split(node *o,node *&a,node *&b,int k)//分成兩顆樹，將其中a的key值均<=k,b的key值均>k
{
    if(!o)a=b=0;
    else
    {
        o->down();
        if(k < o->key)
        {
            b = o;
            split(o->l,a,b->l,k);
        }
        else
        {
            a = o;
            split(o->r,a->r,b,k);
        }
        o->up();
    }
}
//O(log N)
void split(node *o,node *&a,node *&b,int k) //o左邊k個元素分到a中,剩下的元素分到b中
{
    if(!o)a=b=0;
    else
    {
        o->down();
        if(k<=size(o->l))
        {
            b = o;
            split(o->l,a,b->l,k);
        }
        else
        {
            a = o;
            split(o->r,a->r,b,k-size(o->l)-1);
        }
        o->up();
    }
}
//O(log N)

//merge
//• 過程可以簡述成三個問句:
//1.做完了嗎?
//2.誰要當根?
//3.哪邊還沒做完?

//隨機平衡概念
//• 同一棵子樹中,每個節點都有1/n的機率成為那棵子樹的根n是子樹的大小
//• 現在要合併a,b兩棵樹,a有1/size(a)的機率成為a子樹的根;b有1/size(b)的機率成為b子樹的根,則:
//      a成為整棵樹的根有size(a)/(size(a)+size(b))的機率(設為A)
//      b成為整棵樹的根有size(b)/(size(a)+size(b))的機率(設為B)
//• 因為    A*(1/size(a)) = 1/(size(a)+size(b))
//          B*1/size(b) = 1/(size(a)+size(b))
node *merge(node *a,node *b)
{
    if(!a||!b)return a?a:b;
    if(rand()%(a->size+b->size)<a->size)
    {
        a->down();
        a->r=merge(a->r,b);
        a->up();
        return a;
    }
    else
    {
        b->down();
        b->l=merge(a,b->l);
        b->up();
        return b;
    }
}
//O(log N)


////////////////////////////平衡樹基本操作/////////////////////////////
//insert
node *insert(node *o,int key)
{
    node *a,*b;
    split(o,a,b,key);
    return merge(merge(a,new node(key)),b);
}
//delete
bool erase(node *&o,int key)
{
    if(!o)return 0;//target not found
    if(o->key==key)
    {
        node *tmd=o;
        o=merge(o->l,o->r);
        delete tmd;
        return 1;//sucess
    }
    else
    {
        bool is;
        if(key<o->key)
            is=erase(o->l,key);
        else 
            is=erase(o->r,key);
        if(is)
        {
            --o->size;
            return 1;
        }
    return 0;
    }
}

//查詢第K小
//第一個實用的地方就是他是支
//援動態插入刪除和查詢第k小
//元素的資料結構
node *kth(node *o,int k)
{
    if(k<=size(o->l))   return kth(o->l,k);
    if(k==size(o->l) + 1)   return o;
    return kth(o->r,k - size(o->l) - 1);
}

//區間操作-懶惰標記
//• 跟線段樹一樣,我們可以增加一個懶惰標記tag,我們先打個標記在這個區間上,要用到這個區間的時候在把標記往下推
//• 需要再node裡增加tag(懶惰標記),ma(最大值)兩個標記
inline void up()        //up()改寫
{
    size=1;
    ma=key;
    if(l)
    {
        size+=l->size;
        ma=max(ma,l->ma+l->tag);
    }
    if(r)
    {
        size+=r->size;
        ma=max(ma,r->ma+r->tag);
    }
}
inline void down()      //改寫down()
{
    key+=tag;
    if(l)l->tag+=tag;
    if(r)r->tag+=tag;
    tag=0;
}
//詢問
int ask(node *&o,int l,int r)
{
    node *a,*b,*c;
    split(o,a,b,l-1);
    split(b,b,c,r-l+1);
    int ans = b->ma+b->tag;
    o = merge(a,merge(b,c));
    return ans;
}
//修改
int add(node *&o,int l,int r,int v)
{
    node *a,*b,*c;
    split(o,a,b,l-1);
    split(b,b,c,r-l+1);
    b->tag += v;
    o = merge(a,merge(b,c));
}

