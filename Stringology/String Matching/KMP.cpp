// Knuth Morris Pratt algorithm
//
//    i
//    AABZABZABCZ
//    j
//    ABZABC
//
//    //相同向前走
//
//     i
//    AABZABZABCZ
//     j
//    ABZABC
//
//    //不同跳回頭
//
//     i
//    AABZABZABCZ
//    j
//    ABZABC
//
//failure function
//
//           0 1 2 3 4 5
//        i  ^
//           A B Z A B C      //A(j + 1) != B(i + 1)
//        j^                  //j = array[j + 1]
//array     -1                //array[i + 1] = j
//
//           0 1 2 3 4 5
//        i
//           A B Z A B C
//        j
//array     -1-1
//
//           0 1 2 3 4 5
//        i      ^
//           A B Z A B C      //A(j + 1) == B(i + 1)
//        j^                  //j++
//array     -1-1-1            //array[i + 1] = j(已++)
//
//           0 1 2 3 4 5
//        i
//           A B Z A B C
//        j
//array     -1-1-1 0
//
//           0 1 2 3 4 5
//        i
//           A B Z A B C

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
        clog << failure_array[i] << " ";
    }
    clog << endl;

    cout << s << endl;

    return 0;
}
