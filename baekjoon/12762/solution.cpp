#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<vector<int>> len(n, vector<int>(2, 1));
    int maxl = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (h[j] > h[i]) len[i][0] = max(len[i][0], len[j][0] + 1);
            if (h[j] < h[i]) len[i][1] = max(len[i][1], max(len[j][0], len[j][1]) + 1);
        }
        maxl = max(maxl, max(len[i][0], len[i][1]));
    }

    cout << maxl << '\n';
}