#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        set<int> s;
        for (int a: a) {
            if (a >= 0) s.insert(a);
        }
        cout << (s.empty() || (s.size() == 1 && *s.begin() != 0) ? "YES\n" : "NO\n");
    }
}