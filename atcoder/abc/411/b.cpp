#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> d(n - 1);
    for (auto &d: d) cin >> d;
    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        for (int j = i; j < n - 1; j++) {
            cur += d[j];
            cout << cur << ' ';
        }
        cout << '\n';
    }
}