#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> Vec;
    for(int i = 0;i < 10;i++)
        Vec.push_back(i);
//    Vec.erase(Vec.begin() + 5);


    int j = 0;
    for(int i:Vec)
    {
        Vec.erase(Vec.begin() + j);
        cout << i << " ";
//        Vec.push_back(i);
    }
    cout << endl;
    for(int i:Vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
