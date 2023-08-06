#include <bits/stdc++.h>
using namespace std;

int dst[10][10];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dst[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    vector<int> per(n);
    for (int i = 0; i < n; i++) per[i] = i;
    int mind = 1000000;
    do {
        int prev = k;
        int d = 0;
        for (int v: per) {
            if (v == k) continue;
            d += dst[prev][v];
            prev = v;
        }
        mind = min(mind, d);
    } while (next_permutation(per.begin(), per.end()));
    cout << mind << '\n';
}