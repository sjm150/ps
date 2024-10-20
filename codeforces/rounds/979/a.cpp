#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        cout << (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end())) * (n - 1) << '\n';
    }
}