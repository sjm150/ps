#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int i = 0, cnt = 0;
        while (i < n) {
            if (i <= n - 5 && s.substr(i, 5) == "mapie") {
                cnt++;
                i += 3;
            } else if (i <= n - 3) {
                string ss = s.substr(i, 3);
                if (ss == "map") {
                    cnt++;
                    i += 2;
                } else if (ss == "pie") {
                    cnt++;
                    i += 2;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        cout << cnt << '\n';
    }
}