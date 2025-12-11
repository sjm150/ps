#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    if (n % 2) {
        for (int i = 1; i < n; i++) {
            ans[i][i - 1] = ans[i][i] = i;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) ans[i][j] = 1;
            if (i % 2 == 0) ans[i][i] = n;
        }
    }
    for (auto &a: ans) {
        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}