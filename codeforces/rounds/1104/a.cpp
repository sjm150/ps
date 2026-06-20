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
        int mn = 1e6, sum = 0;
        for (int a: a) {
            mn = min(mn, a);
            sum += mn;
        }
        cout << sum << '\n';
    }
}