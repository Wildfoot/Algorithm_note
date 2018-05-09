#include <iostream>
#define MAXN 1<<10
using namespace std;

int failure_array[MAXN] = {-1};

string s, s1, s2;

int failure_function()
{
    int n = s.length();
    for(int i = 0, j = -1;i < (n - 1);i++)
    {
        if(s[i + 1] == s[j + 1])
        {
            failure_array[i + 1] = j + 1;
            j++;
        }
        else
        {

            j = failure_array[j + 1];
            failure_array[i + 1] = j;
        }
        if(failure_array[i + 1] == s2.length() - 1)
            return i + 1 - s2.length();
    }
    return -1;
}

int main()
{
    getline(cin, s1);
    getline(cin, s2);
    s = s2 + s1;

    int ans = failure_function();
    cout << ans << " ~ " << ans + s2.length() << endl;

    //DEBUG
    for(int i = 0;i < s.length();i++)
    {
        cout << failure_array[i] << " ";
    }
    cout << endl << s << endl;
    return 0;
}
