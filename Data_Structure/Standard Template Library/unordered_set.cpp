#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s; //O(N) 較慢
    //set <int> s; //O(N)
    s.insert(15);               //O(1)
    s.insert(20);

    for(int i = 0;i < 10;i++)
    {
        s.insert( rand()%100 );
    }

    if( s.find(15) != s.end() ) //O(1)
    {

    }

    for(int i:s)
    {
        cout << i << " ";
    }
}
