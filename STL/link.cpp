#include <iostream>

using namespace std;


struct PAK
{
    int i;//value
    PAK *left;
    PAK *right;
};
int main()
{
    /*
    PAK head;   // 1 4 2
    head.right = new PAK();
    head.right->i = 1;

    head.right->right = new PAK();
    head.right->right->i = 4;

    head.right->right->right = new PAK();
    head.right->right->right->i = 2;

    for(PAK *ii = head.right; ii != NULL;ii = ii->right)
        cout << ii->i << endl;
    return 0;
    */
    int n = 5;
    PAK head;
    PAK *l;

    head.right = new PAK();
    l = head.right;

    for(int i = 0;i < n;i++)
    {
        int y;
        cin >> y;
        l->i = y;
        l->right = new PAK();
        l = l->right;
    }

    for(PAK *ii = head.right; ii != NULL;ii = ii->right)
        cout << ii->i <<" "<< ii->right << endl;

    return 0;

}
