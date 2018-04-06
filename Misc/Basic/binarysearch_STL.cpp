// 
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>
#include <algorithm>

#define INF 2147483647
#define EPS 1e-9
#define MAX 10000

using namespace std;

struct data_struct
{
    int index, data;

    bool operator < (const struct data_struct &rhs) const
    {
        return data < rhs.data;
    }

    //for lower_bound compare between data_struct and int(which you want to search) 
    bool operator < (const int val) const
    {
        return data < val;
    }

};

//for upper_bound
bool operator < (const int int_val, const data_struct data_val)
{
    return int_val < data_val.data;
}

static data_struct arr[MAX];
static int maxN;

void print_arr()
{
    for(int i = 0;i < maxN;i++)
    {
        cout << arr[i].index << "\t";
    }
    cout << endl;
    for(int i = 0;i < maxN;i++)
    {
        cout << arr[i].data << "\t";
    }
    cout << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    while(true)
    {
        cout << "amount of number : ";
        cin >> maxN;
        data_struct array[maxN];
        for(int i = 0;i < maxN;i++)
        {
            cin >> arr[i].data;
            arr[i].index = i;
        }
        print_arr();

        sort(arr, arr + maxN);

        print_arr();


        int Q;
        cout << "amount of question : ";
        cin >> Q;
        while(Q--)
        {
            int keyin;
            cin >> keyin;

            //if you don't want write another operator< for data_struct and interger, just pass which you want search to data_struct variable;
//            data_struct another_solution;
//            another_solution.data = keyin;
//            cout << "lower bound : " << lower_bound(arr, arr + maxN, another_solution) - arr << " address : " << lower_bound(arr, arr + maxN, another_solution) << endl;

            cout << "lower bound : " << lower_bound(arr, arr + maxN, keyin) - arr << " address : " << lower_bound(arr, arr + maxN, keyin) << endl;
            cout << "upper bound : " << upper_bound(arr, arr + maxN, keyin) - arr << " address : " << upper_bound(arr, arr + maxN, keyin) << endl;
        }

    }

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

