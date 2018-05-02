// 
// WildfootW 2018
// https://github.com/Wildfoot

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9
#define MAX 10

using namespace std;

void function_pointer(int *param)
{
    for(int i = 0;i < MAX;i++)
        cout << param[i] << " ";
    cout << endl;
}
void function_sized_array(int param[MAX])
{
    for(int i = 0;i < MAX;i++)
        cout << param[i] << " ";
    cout << endl;
}
void function_unsized_array(int param[])
{
    for(int i = 0;i < MAX;i++)
        cout << param[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));
    int param[MAX];
    for(int i = 0;i < MAX;i++)
    {
        param[i] = rand() % INF;
    }
    function_pointer(param);
    function_sized_array(param);
    function_unsized_array(param);

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

