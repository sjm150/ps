#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    vector<vector<int>> sum;
    sum.push_back(vector<int>(26, 0));
    for (char c: s) {
        sum.emplace_back(sum.back());
        sum.back()[c - 'a']++;
    }

    int q; cin >> q;
    while (q--) {
        char a; cin >> a;
        int  l, r; cin >> l >> r;
        a -= 'a';
        cout << sum[r + 1][a] - sum[l][a] << '\n';
    }
}