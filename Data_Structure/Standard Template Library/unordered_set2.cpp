#include <bits/stdc++.h>

using namespace std;


struct st
{
    int i;
    int j;
    int c;
};
namespace std
{
    template<> struct hash<st> {
        long operator() (const st &data) const {
            return hash<int>()(data.i) ^ hash<int>()(data.j) ^ hash<int>()(data.c);
        }
    };
}
bool operator == (const st &a, const st &b)
{
    return      a.c == b.c
            &&  a.i == b.i
            &&  a.j == b.j;
}
int main()
{
    unordered_set<st> s;

    st A = {1,2,3};
    cout << hash<st>()(A);
}
