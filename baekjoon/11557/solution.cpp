#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, string>> ls(n);
        for (auto &[l, s]: ls) cin >> s >> l;
        cout << max_element(ls.begin(), ls.end())->second << '\n';
    }
}