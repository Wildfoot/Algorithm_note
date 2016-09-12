#include <iostream>
using namespace std;
 
void print(int ans,int base,int n)
{
    cout << "ans = " << ans << " base = " << base << " n = "<< n << endl;
}

int POW(int a,int n,int m)      // a ^ n % m
{
    int ans = 1,base = a;
    while(n)
    {
        if(n % 2 == 1) 
        {
            ans *= base;    //print(ans,base,n);    
        }
        base *= base;   //print(ans,base,n);        
        ans %= m;       //print(ans,base,n);        
        base %= m;      //print(ans,base,n);        
        n /= 2;         //print(ans,base,n);        
    }
    return ans % m;
    //return ans;
}

 
int main()
{
    int a, n, m;
    while(cin >> a >> n >> m) 
        cout << POW(a,n,m) << endl;

    return 0;
}
