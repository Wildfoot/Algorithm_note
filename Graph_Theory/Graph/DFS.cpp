#include <iostream>
#include <vector>
#include <stack>
#include"memory.h"

using namespace std;

typedef long long ll;

bool used[100]; 
vector<int> V[100];

void DFS(int n)
{
    used[n] = true;
    cout << n << " ";
    for(int e:V[n])
    {
        if(!used[e])
        {
            //used[e] = true;
            DFS(e);
        }
    }
}


int main()
{
	int n, m;
	cin >> n >> m;
	while ( m-- )
	{
        int a, b;
		cin >> a >> b;
		V[a].push_back(b); 
	}
	
	//Depth First Search
	stack<int> qu;
	qu.push(0);

	memset(used,0,sizeof(used));
	used[0] = true;

	while ( !qu.empty() )
	{
		int k = qu.top();
		qu.pop();
		cout << k << ' ';
		for ( int e:V[k] )      //e = 陣列裡的值
		{
            //cout << "|" << e <<"|";
			if ( !used[e] )
			{
				used[e] = true; 
				qu.push(e);
			}
		}
	}
    cout << endl;
    //function
	memset(used,0,sizeof(used));
    DFS(0);

    return 0;
}

