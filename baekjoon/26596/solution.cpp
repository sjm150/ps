#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    map<string, int> sum;
    while (m--) {
        string s; cin >> s;
        int x; cin >> x;
        sum[s] += x;
    }
    vector<int> v;
    for (auto &[s, x]: sum) v.push_back(x);
    sort(v.begin(), v.end());
    bool ok = false;
    for (int i = 0; i < v.size(); i++) {
        if (binary_search(v.begin() + i + 1, v.end(), v[i] * 1618 / 1000)) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Delicious!\n" : "Not Delicious...\n");
}