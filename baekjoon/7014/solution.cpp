#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    for (int kk = 1; kk <= k; kk++) {
        string s, t; cin >> s >> t;
        int n = s.size();
        auto get = [&](int i) {
            if (s[i] == 'X' && t[i] == 'O') return 1;
            else if (s[i] == 'O' && t[i] == 'X') return -1;
            else return 0;
        };
        int ans = 0;
        bool ok = false;
        for (; !ok; ans++) {
            ok = true;
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                cnt += get(i - 1);
                if ((cnt > 0 && s[i] == 'O') || (cnt < 0 && s[i] == 'X')) {
                    ok = false;
                    cnt += get(i);
                    swap(s[i - 1], s[i]);
                    i++;
                };
            }
        }
        cout << "Data Set " << kk << ":\n";
        cout << ans - 1 << "\n\n";
    }
}