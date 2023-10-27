#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> p(n, 0);
    for (int i = n / 2; i < n; i++) p[i] = 1;

    int mind = 1e9;
    do {
        vector<int> idcs[2];
        int sum[2] = {0, 0};
        for (int i = 0; i < n; i++) idcs[p[i]].push_back(i);
        for (int k = 0; k < 2; k++) {
            auto& idx = idcs[k];
            for (int i = 0; i < n / 2; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    sum[k] += s[idx[i]][idx[j]] + s[idx[j]][idx[i]];
                }
            }
        }
        mind = min(mind, abs(sum[0] - sum[1]));
    } while (next_permutation(p.begin(), p.end()));

    cout << mind << '\n';
}