// Longest Increasing Sub-sequence
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define EPS 1e-9
#define MAX 10000

// Naïve solutions:
// For every sub-sequence, check if it is LIS
// - Every sub-sequence, O(2N).
// - For each sub-sequence checking needs O(N).
// - Total: O(N*2^N)

// LIS
// Find the previous number with longest LIS.
// index: 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
// num  : 0  8  4  12 2  10 6  14 1  9  5  13 3  11 7  15
// LIS  : 1  2  2  3  2  3  3  4  2  4  3  5  3  5  4  6
// - Every element, O(N)
// - Each element, check previous elements, O(N)
// - Total: O(N*N)

////////////////// optimization //////////////////
// use a shorter array recording which is the smallest number when LIS's length is [k]. (because you just need to know how longest the sub-sequence is)
// and use binary search to know which length you need to update.
// LIS[k]:0
// LIS[k]:0  8
// LIS[k]:0  4
// LIS[k]:0  4  12
// LIS[k]:0  2  12
// ...
// LIS[k]:0  1  3  7  11 15 
// (k means the length of the sub-sequence)

////////////////// output the solution ////////////////// 
//
// Find the number backwards
// LIS[i] = LIS[k]-1 && num[i] < num[k], and so on
//
// Additional array pre[]
// record the pre index while processing LIS
// index: 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
// num  : 0  8  4  12 2  10 6  14 1  9  5  13 3  11 7  15
// LIS  : 1  2  2  3  2  3  3  4  2  4  3  5  3  5  4  6
// Pre  : 0  1  1  2  1  2  5  4  11 7  3  10 5  10 7  14

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    while(true)
    {
        int num[MAX], maxN;
        cout << "amount of number : "; 
        cin >> maxN;
        if(!maxN)
            break;
        for(int i = 0;i < maxN;i++)
            cin >> num[i];

        vector<int> LIS;
        LIS.push_back(num[0]);
        // for output solution (using way "backward")
        vector<int> LIS_record;
        LIS_record.push_back(1);
        //////////////////////
        for(int i = 1;i < maxN;i++)
        {
            if(num[i] >= LIS.back())
            {
                LIS.push_back(num[i]);
                LIS_record.push_back(LIS.size());
                continue;
            }
            //binarysearch
            int index_to_change = upper_bound(LIS.begin(), LIS.end(), num[i]) - LIS.begin();
            LIS[index_to_change] = num[i];
            LIS_record.push_back(index_to_change + 1);
        }
        cout << "length of longest increasing sub-sequence is : " << LIS.size() << endl;

        // output solution
        int length_of_lis_now = LIS.size(), next_num_of_lis_now = INF;
        vector<int> LIS_output;
        for(int i = maxN - 1;i >= 0;i--)
        {
            if(LIS_record[i] != length_of_lis_now || num[i] > next_num_of_lis_now)
                continue;

            next_num_of_lis_now = num[i];
            length_of_lis_now--;
            LIS_output.push_back(next_num_of_lis_now);
        }
        for(int i = LIS_output.size() - 1;i >= 0;i--)
            cout << LIS_output[i] << " ";
        cout << endl;
    }

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

