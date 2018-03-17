// 
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>
// Eratosthenes
#include <cmath>
#include <cstring>
// 6n±1 Method
#include <vector>

#define INF 2147483647
#define MAX 10000000

using namespace std;

//sieve of Eratosthenes
//由小到大選擇質數，並刪除其倍數
bool eratosthenes_is_prime[MAX];
void make_prime_eratosthenes()
{
    memset(eratosthenes_is_prime, 1, sizeof(eratosthenes_is_prime));
    eratosthenes_is_prime[0] = false;
    eratosthenes_is_prime[1] = false;

    for(int i = 2;i <= sqrt(MAX);i++)
    {
        if(eratosthenes_is_prime[i])
        {
            for(int j = i * 2;j < MAX;j += i)
                eratosthenes_is_prime[j] = false;
        }
    }
}

//6n±1 Method (較慢)
//拿2 和3 這兩個質數先篩過一遍，剩下的數字則用除法驗證是不是質數。
//最小公倍數6，6n、6n+2、6n+3、6n+4是2或3的倍數，只要判斷6n+1和6n-1即可。
vector<int> prime_6n;
bool is_prime_6n(int n)
{
    for(int i = 0;prime_6n[i] * prime_6n[i] <= n;i++)
    {
        if(n % prime_6n[i] == 0)
            return false;
    }
    return true;
}
void make_prime_6n()
{
    prime_6n.push_back(2);
    prime_6n.push_back(3);
    //gap jump between 4 and 2
    for(int i = 5, gap = 2;i < MAX;i += gap, gap = 6 - gap)
        if(is_prime_6n(i))
            prime_6n.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    make_prime_eratosthenes();
    make_prime_6n();

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

