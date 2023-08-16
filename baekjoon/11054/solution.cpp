#include <iostream>
using namespace std;

int a[1000], len[2][1000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    len[0][0] = len[1][0] = 1;
    for (int i = 1; i < n; i++) {
        len[0][i] = len[1][i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) len[0][i] = max(len[0][i], len[0][j] + 1);
            else if (a[j] > a[i]) len[1][i] = max(len[1][i], max(len[0][j], len[1][j]) + 1);
        }
    }
    int maxl = 0;
    for (int i = 0; i < n; i++) maxl = max(maxl, max(len[0][i], len[1][i]));
    cout << maxl << '\n';
}