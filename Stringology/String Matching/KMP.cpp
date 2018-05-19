/* Knuth Morris Pratt algorithm
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

//  define Fail function
//      能知道匹配失敗時,B 要對齊哪裡繼續匹配(適用於B有重複子字串)
//      後衍生為將B字串放在前面直接使用這步比對字串
//
//           0 1 2 3 4 5        //S[j + 1] != S[i + 1]
//           A B Z A B C        //j = fail(j + 1)
//        i  ^                  //fail(i + 1) = j
//        j^
//fail()    -1
//
//           0 1 2 3 4 5
//           A B Z A B C
//        i    ^
//        j^
//fail()    -1-1
//
//           0 1 2 3 4 5        //S[j + 1] == S[i + 1]
//           A B Z A B C        //j++
//        i      ^              //fail(i + 1) = j
//        j^
//fail()    -1-1-1
//
//           0 1 2 3 4 5
//           A B Z A B C
//        i        ^
//        j  ^
//fail()    -1-1-1 0
//
//           0 1 2 3 4 5
//           A B Z A B C
//        i          ^
//        j    ^
//fail()    -1-1-1 0 1
//
//           0 1 2 3 4 5
//           A B Z A B C
//        i            ^
//        j^
//fail()    -1-1-1 0 1-1

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

class KMP
{
    private:
        inline string fix_alignment(string para)   //DEBUG
        {
            const int alignment_num = 3;
            para.resize(alignment_num, ' ');
            return para;
        }

    protected:
        int * failure;
        string stringA, stringB;
        int substring_position; //answer stringA[substring_position] == stringB[0]

    public:
        void calculate_failure();
        void matching();
        void print_failure() //DEBUG
        {
            for(int i = 0;i < stringB.length();i++)
                clog << fix_alignment(string(1, stringB[i]));
            clog << endl;
            for(int i = 0;i < stringB.length();i++)
                clog << fix_alignment(to_string(failure[i]));
            clog << endl;
        }
        int answer()
        {
            if(substring_position == -1)
            {
                clog << "no matching!" << endl;
            }
            else
            {
                clog << "matching!" << endl;
                clog << stringA << endl;
                for(int i = 0;i < substring_position;i++)
                    clog << " ";
                clog << stringB << endl;
            }
            return substring_position;
        }

        KMP(string A, string B):
            stringA(A), stringB(B)
        {
            substring_position = -1;
            failure = new int[stringB.length()];
        }
        ~KMP()
        {
            delete[] failure;
        }
};

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    while(true)
    {
        string stringA, stringB;
        cout << "String A: ";
        getline(cin, stringA);
        cout << "String B: ";
        getline(cin, stringB);

        KMP test{stringA, stringB};
        test.calculate_failure();
        test.print_failure();
        test.matching();
        test.answer();
    }
    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

void KMP::calculate_failure()
{
    for(int i = 0;i < stringB.length();i++)
        failure[i] = -1;
    for(int i = 0, j = -1;(i + 1) < stringB.length();i++)
    {
        if(stringB[i + 1] == stringB[j + 1])
        {
            failure[i + 1] = j + 1;
            j++;
        }
        else
        {
            j = failure[j + 1];
            failure[i + 1] = j;
        }
    }
}
void KMP::matching()
{
    int cur_pos = 0;
    for(int i = 0;i < stringA.length();i++)
    {
        if(stringA[i] == stringB[cur_pos])
        {
            cur_pos++;
        }
        else
        {
            cur_pos = failure[cur_pos] + 1;
        }
        if(cur_pos == stringB.length())
        {
            substring_position = i - stringB.length() + 1;
            return;
        }
    }
    return;
}
