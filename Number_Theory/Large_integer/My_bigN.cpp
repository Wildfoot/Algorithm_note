// Big Number
// Accepted
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string operator*(string& , string&);

int main()
{
	string a,b;
	while(cin >> a >> b)
		cout << a * b << endl;
	return 0;
}
string operator*(string& a,string& b)
{

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//反轉輸入自元(a[0] switch a[end]])
	
	for(int k = 0;k < a.size();k++) a[k] = a[k] - '0';
	for(int k = 0;k < b.size();k++) b[k] = b[k] - '0';
	
	string c(a.size() + b.size(),0); 
	//字串大小設定 初始值為0
	
	for(int i = 0;i < a.size();i++)
	{
		for(int j = 0;j < b.size();j++)
		{
			c[i + j] = c[i + j] + (a[i] * b[j]);
		}
		//乘法
	
		for(int j = 0;j < c.size();j++)
			if(j + 1 < c.size())
			{
				c[j + 1] = c[j + 1] + (c[j] / 10);
				c[j] = c[j] % 10;
			}
		//進位
	}
	
	int n = c.size();
	while(n && c[n -1] == 0)
		n--;
	c.resize(n);
	//消掉最前面的0
	
	for(int i = 0;i < c.size();i++)
		c[i] = c[i] + '0';
	//轉回字元
	
	if(c.size() == 0)
		c = "0";
	// 0 例外
	
	reverse(c.begin(),c.end());
	return c;

}
