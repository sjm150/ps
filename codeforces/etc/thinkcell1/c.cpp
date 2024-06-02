#include <bits/stdc++.h>
using namespace std;

int find(map<int, int>& m, int x) {
    auto it = m.find(x);
    if (it == m.end()) return x;
    return it->second = find(m, it->second);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> m;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x = find(m, a[i] + i + 1);
            if (x >= a[i] + 1) {
                b.push_back(x);
                m[x] = x - 1;
            }
        }

        sort(b.begin(), b.end(), greater<int>());
        for (int b: b) cout << b << ' ';
        cout << '\n';
    }
}