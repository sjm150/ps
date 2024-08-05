#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<int> o, e;
        for (int a: a) {
            if (a % 2) o.push_back(a);
            else e.push_back(a);
        }
        if (o.empty() || e.empty()) {
            cout << 0 << '\n';
            continue;
        }
        sort(e.begin(), e.end());
        int sz = e.size();
        vector<long long> esum(sz + 1);
        esum[0] = *max_element(o.begin(), o.end());
        bool ad = false;
        for (int i = 0; i < sz; i++) {
            if (e[i] > esum[i]) {
                ad = true;
                break;
            } else {
                esum[i + 1] = e[i] + esum[i];
            }
        }
        cout << e.size() + ad << '\n';
    }
}