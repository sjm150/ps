#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int e = 0, o = 0;
        for (int a: a) {
            if (a % 2) o++;
            else e++;
        }

        if (o && e) cout << accumulate(a.begin(), a.end(), 0ll) - o + 1 << '\n';
        else cout << *max_element(a.begin(), a.end()) << '\n';
    }
}