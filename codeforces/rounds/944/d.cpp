#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int cnt = 1;
        bool chk = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] != s[i]) {
                if (!chk && s[i - 1] == '0')  {
                    chk = true;
                    continue;
                }
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}