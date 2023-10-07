#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<bool> req;
int cnt;

void init_req() {
    req = vector<bool>(n + 1, false);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') continue;
        req[i] = true;
        cnt++;
        for (int j = i; j <= n; j += i) s[j - 1] = '0' + '1' - s[j - 1];
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> n >> s;
        init_req();
        int q; cin >> q;
        while (q--) {
            int b; cin >> b;
            if (req[b]) {
                req[b] = false;
                cnt--;
            } else {
                req[b] = true;
                cnt++;
            }
        }
        cout << "Case #" << testcase << ": " << cnt << '\n';
    }
}