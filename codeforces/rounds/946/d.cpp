#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<char, int> inst = {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ins(n);
        for (int &i: ins) {
            char c; cin >> c;
            i = inst[c];
        }
        vector<int> cnt(4, 0);
        for (int i: ins) cnt[i]++;

        if ((cnt[0] & 1) == (cnt[1] & 1) && (cnt[2] & 1) == (cnt[3] & 1)) {
            for (int i = 0; i < 4; i++) cnt[i] /= 2;
            string ans = "";
            for (int i: ins) {
                if (cnt[i]) {
                    ans += "RH"[(i >> 1) & 1];
                    cnt[i]--;
                } else {
                    ans += "HR"[(i >> 1) & 1];
                }
            }
            if (ans.find('R', 0) == string::npos || ans.find('H', 0) == string::npos) cout << "NO\n";
            else cout << ans << '\n';
        } else {
            cout << "NO\n";
        }
    }
}