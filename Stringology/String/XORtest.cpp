#include <iostream>
using namespace std;
int main(        ) 
{
    /*
    int ans[21], ans_10 = 0;
    for(int i = 0;i < 21;i++)
    {
        cout << i;
        cin >> ans[i];
        if(ans[i])
        {
            int temp = 1;
            for(int j = 0;j < 20 - i;j++)
                temp = temp * 2;
            ans_10 = ans_10 + temp;
        }
    }
    cout << ans_10 << " ";
    */
    cout << "100000" << endl;
    for(int i = 2097150;i > 2097150 - 100000;i--)
    {
        cout << i << endl;
    }
    return 0;
}
