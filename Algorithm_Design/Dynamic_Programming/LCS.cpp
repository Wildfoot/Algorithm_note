// Longest Common Sub-sequence
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>
#include <cstring>
#include <stack>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

// Naïve solutions:
// For every sub-sequence in S1, check if it is a sub-sequence of S2.
// - Every sub-sequence, O(2^N), N is length of S1
// - For each sub-sequence checking needs O(M), M is length of S2
// - Total: O(M*2^N)

// LCS
// For example:
//  s1 = '0' + "providence" (length = 10)
//  s2 = '0' + "president"  (length = 9)
//  if s1[10] == s2[9]:
//      LCS[10][9] = LCS[9][8] + 1
//  if s1[10] != s2[9]:
//      LCS[10][9] = max(LCS[10][8], LCS[9][9])

///////////////// output solution /////////////////
// record LCS and find solution backward
//   p r o v i d e n c e
// p 1*1 1 1 1 1 1 1 1 1
// r 1 2*2 2 2 2 2 2 2 2
// e 1 2 2 2 2 2 3 3 3 3
// s 1 2 2 2 2 2 3 3 3 3
// i 1 2 2 2 3*3 3 3 3 3
// d 1 2 2 2 3 4*4 4 4 4
// e 1 2 2 2 3 4 5*5 5 5
// n 1 2 2 2 3 4 5 6*6 6
// t 1 2 2 2 3 4 5 6 6 6

#define MAX 10000

static string s1, s2;
static int LCS[MAX][MAX];
static bool LCS_visit[MAX][MAX];
////// for output ///////
static stack<char> LCS_output;
/////////////////////////

int find_LCS(int m, int n)
{
    if(m == -1 || n == -1)
        return LCS[m][n] = 0;
    if(LCS_visit[m][n])
        return LCS[m][n];
    LCS_visit[m][n] = true;
    if(s1[m] == s2[n])
        return LCS[m][n] = find_LCS(m - 1, n - 1) + 1;
    else
        return LCS[m][n] = max(find_LCS(m - 1, n), find_LCS(m, n - 1));
}

void print_LCS()
{
    cout << "\t";
    for(int i = 0;i < s2.length();i++)
    {
        cout << s2[i] << "\t";
    }
    cout << endl;
    for(int i = 0;i < s1.length();i++)
    {
        cout << s1[i] << "\t";
        for(int j = 0;j < s2.length();j++)
        {
            cout << LCS[i][j] << "\t";
        }
        cout << endl;
    }
}

void find_solution_backward(int m, int n)
{
    if(LCS[m][n] == 0)
        return;
    if(LCS[m][n] == LCS[m - 1][n])
    {
        find_solution_backward(m - 1, n);
        return;
    }
    if(LCS[m][n] == LCS[m][n - 1])
    {
        find_solution_backward(m, n - 1);
        return;
    }
    if(LCS[m][n] == LCS[m - 1][n - 1] + 1)
    {
        LCS_output.push(s1[m]);
        find_solution_backward(m - 1, n - 1);
        return;
    }
    cout << "WTF" << endl;
}

void clear_stack( stack<char> &q )
{
    stack<char> empty;
    swap(q, empty);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    while(!cin.eof())
    {
        memset(LCS, 0, sizeof(LCS));
        memset(LCS_visit, false, sizeof(LCS_visit));
        clear_stack(LCS_output);
        cout << "keyin two sequence to find longest common sub-sequence :" << endl;
        getline(cin, s1);
        getline(cin, s2);
        cout << "length of LCS is : " << find_LCS(s1.length() - 1, s2.length() - 1) << endl;

        print_LCS();

        /////////////// output solution ////////////////
        find_solution_backward(s1.length() - 1, s2.length() - 1);
        while(!LCS_output.empty())
        {
            cout << LCS_output.top();
            LCS_output.pop();
        }
        cout << endl;
    }

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

