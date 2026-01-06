#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    int sz = 1 << n;
    vector<int> mx(sz, 0);

    for (int i = 1; i < sz; i++) {
        vector<int> s;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s.push_back(a[j]);
        }

        int sum = accumulate(s.begin(), s.end(), 0);
        if (sum % 2) continue;

        int m = sum / 2;
        vector<bool> poss(m + 1, false);
        poss[0] = true;
        for (int s: s) {
            for (int j = m; j >= s; j--) {
                if (poss[j - s]) poss[j] = true;
            }
        }

        if (poss[m]) mx[i] = m;
    }

    for (int i = 1; i < sz; i++) {
        for (int j = 1; j < sz; j *= 2) mx[i | j] = max(mx[i | j], mx[i]);
    }

    int ans = 0;
    for (int i = 1; i < sz; i++) ans = max(ans, mx[i] * mx[sz - 1 - i]);
    cout << (ans ? ans : -1) << '\n';
}