#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string ans = "ABCDE\n";
    bool poss = true;
    while (n--) {
        bool chk[5] = {};
        string s; cin >> s;
        if (!poss) continue;
        string t = "FFFFF";
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'G') {
                t[i] = 'A' + i;
                chk[i] = true;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'Y') {
                poss = false;
                for (int j = (i + 1) % 5; j != i; j = (j + 1) % 5) {
                    if (chk[j]) continue;
                    t[i] = 'A' + j;
                    poss = chk[j] = true;
                    break;
                }
                if (!poss) break;
            }
        }
        ans += t + '\n';
    }
    cout << (poss ? ans : "IMPOSSIBLE\n");
}