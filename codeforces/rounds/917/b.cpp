#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        set<char> appr;
        int cnt = 0;
        for (char c: s) {
            appr.insert(c);
            cnt += appr.size();
        }

        cout << cnt << '\n';
    }
}