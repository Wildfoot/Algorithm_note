#include<iostream>
#include<vector> 
#include<queue>
#include"memory.h"

using namespace std;

typedef long long ll;

bool used[100]; 
vector<int> V[100];

/*void BFS(int n)
{
}
*/

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
	
	//BreadthFirstSearch
	queue<int> qu;
	qu.push(0);

	memset(used,0,sizeof(used));
	used[0] = true;

	while ( !qu.empty() )
	{
		int k = qu.front();
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
	return 0;
    //function

	//memset(used,0,sizeof(used));
    //BFS(0);
}

