#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> qu;
    for(int i = 0;i < 10;i++)
    {
        qu.push(i);
    }
    cout << qu.size() << endl;
  
    while(!qu.empty())
    {
        cout << qu.front() << endl;
        qu.pop();
    }

    return 0;
}
