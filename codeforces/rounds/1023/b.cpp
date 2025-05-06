#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        (*max_element(a.begin(), a.end()))--;
        cout << (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) <= k && sum % 2 == 1 ? "Tom\n" : "Jerry\n");
    }
}