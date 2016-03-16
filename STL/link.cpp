struct PAK
{
    int i;//value
    PAK *left;
    PAK *right;
}
PAK head;
PAK P;
P.i = 1;
head->right = P;
PAK q;
q.i = 4;
head->right->right = q;

