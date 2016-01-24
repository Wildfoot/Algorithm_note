#include <iostream>
using std::cin;
using std::cout;
#define MAXN 100000
#define INF 2147483647

int bin_search(int arr[], int l, int r, int v) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (arr[m] < v)
        return bin_search(arr, m + 1, r, v);
    else
        return bin_search(arr, l, m, v);
}

int seq[MAXN];
int lea[MAXN + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    lea[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        lea[i] = INF;
    }
    for (int i = 0; i < n; ++i) {
        int pos = bin_search(lea, 0, n, seq[i]);
        lea[pos] = seq[i];
        for (int j = 0; j <= n; ++j) {
            if (lea[j] == -INF)
                cout << "- ";
            else if (lea[j] == INF)
                cout << "+ ";
            else
                cout << lea[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
