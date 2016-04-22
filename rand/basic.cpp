#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    srand( clock() );
    cout << rand() % 2 << endl;
    return 0;
}
