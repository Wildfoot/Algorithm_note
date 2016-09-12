#include <iostream>
#define MAXN 8
using std::cin;
using std::cout;
using std::endl;
//using namespace std;

int binarysearch(int T,int L,int R,int arr[])
{
    cout << "T = " << T << "L = " << L << "R = " << R << "M = " << (L + R) / 2 << endl;
    int M = (L + R) / 2;
    if(T == arr[M])
        return M;

    if(L >= R)
        return -1;

    if(T > arr[M])
        return binarysearch(T,M + 1,R,arr);
    else 
        return binarysearch(T,L,M,arr);
}


int main()
{
    int arr[MAXN];
    for(int i = 0;i < MAXN;i++)
    {
        cin >> arr[i];
    }
    int N;
    cin >> N;
    while(N--)
    {
        int T,ans = 0;
        cin >> T;
        ans = binarysearch(T,0,MAXN - 1,arr);
        if(ans == -1)
            cout << "No such number!" << endl;
        else
            cout << "arr[" << ans << "] = " << arr[ans] << endl;
    }
    return 0;

}
