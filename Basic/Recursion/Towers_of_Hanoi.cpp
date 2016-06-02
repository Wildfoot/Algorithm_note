#include <iostream>

using namespace std;

void hanoi(int n, int start, int temp, int target)
{
    cout << "hanoi(" << n << ", " << start << ", " << temp << ", " << target << ")" << endl;
    if(n == 1)
    {
        cout << "move Disk from " << start << " to " << target << endl;
    }
    else
    {
        hanoi(n - 1, start, target, temp);
        hanoi(1, start, temp, target);
        hanoi(n - 1, temp, start, target);
    }
}
int main()
{
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    return 0;
}
