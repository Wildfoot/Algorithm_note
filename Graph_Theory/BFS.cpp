// Breadth First Search
// WildfootW
// https://github.com/Wildfoot
#include <iostream>
#include <vector> 
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100

bool used[MAX]; 
vector<int> V[MAX];

int main()
{
	int n, m;
    cout << "Amount of node : ";
	cin >> n;
    cout << "Amount of edge : ";
    cin >> m;

/////////////// store the edge in vector //////////////////
    cout << "Enter the edge : (if a edge link between node 1 and node 3, keyin \"1 3\")" << endl;
	while ( m-- )
	{
        int a, b;
		cin >> a >> b;
		V[a].push_back(b);  //單向圖
		//V[b].push_back(a); //雙向圖
	}
	
/////////////////////////// example /////////////////////////
	queue<int> qu;
	qu.push(0);

	memset(used, 0, sizeof(used));
	used[0] = true;

	while ( !qu.empty() )
	{
		int k = qu.front();
		qu.pop();
		cout << k << ' ';
		for ( int e:V[k] )      //e = 陣列裡的值
		{
			if ( !used[e] )
			{
				used[e] = true; 
				qu.push(e);
			}
		}
	}
	return 0;
}

