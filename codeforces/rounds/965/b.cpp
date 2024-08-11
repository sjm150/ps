#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int &p: p) cin >> p;
        for (int i = 1; i < n; i++) cout << p[i] << ' ';
        cout << p[0] << '\n';
    }
}