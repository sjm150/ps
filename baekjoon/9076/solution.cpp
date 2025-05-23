#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(5);
        for (int &a: a) cin >> a;
        a.erase(max_element(a.begin(), a.end()));
        a.erase(min_element(a.begin(), a.end()));
        int mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
        cout << (mx - mn >= 4 ? "KIN" : to_string(a[0] + a[1] + a[2])) << '\n';
    }
}