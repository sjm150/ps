#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int ss = -1, se = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (ss < 0) ss = i;
                se = i;
            }
        }

        if (ss < 0) {
            int cnt = 0, pcnt = 0;
            bool poss = true;
            for (auto c: s) {
                if (c == '(') {
                    cnt++;
                } else if (c == ')') {
                    if (cnt == 0) {
                        if (pcnt) {
                            pcnt--, cnt++;
                            continue;
                        } else {
                            poss = false;
                            break;
                        }
                    }
                    cnt--;
                } else {
                    if (cnt) cnt--, pcnt++;
                    else cnt++;
                }
            }
            if (cnt > 0) poss = false;

            if (poss) cout << "YES\n";
            else cout << "NO\n";
        } else {
            int cnt = 0;
            bool poss = true;
            for (int i = 0; i < ss; i++) {
                if (s[i] == ')') {
                    if (cnt) cnt--;
                    else {
                        poss = false;
                        continue;
                    }
                } else cnt++;
            }
            if (!poss) {
                cout << "NO\n";
                continue;
            }

            cnt = 0;
            poss = true;
            for (int i = s.size() - 1; i > se; i--) {
                if (s[i] == '(') {
                    if (cnt) cnt--;
                    else {
                        poss = false;
                        continue;
                    }
                } else cnt++;
            }
            if (poss) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}