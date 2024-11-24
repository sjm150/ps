#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k, n; cin >> k >> n;
    vector<string> ss(k);
    for (auto &s: ss) cin >> s;
    sort(ss.begin(), ss.end(), [](string &a, string &b) { return a + b > b + a; });
    int mxi = 0;
    for (int i = 1; i < k; i++) {
        if (stoi(ss[mxi]) < stoi(ss[i])) mxi = i;
    }
    for (int i = 0; i < k; i++) {
        if (i == mxi) {
            for (int j = 0; j < n - k; j++) cout << ss[i];
        }
        cout << ss[i];
    }
    cout << '\n';
}