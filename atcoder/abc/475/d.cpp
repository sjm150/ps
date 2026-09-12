#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    int st = 1;
    for (int i = 0; i < n - 1; i++) st *= 10;

    int mx = st * 10;
    vector<bool> isp(mx, true);
    vector<int> p;
    for (int i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        if (i >= st) p.push_back(i);
        for (long long j = (long long)(i) * i; j < mx; j += i) isp[j] = false;
    }

    auto calc = [&]() {
        for (int p: p) {
            vector<char> c(10, 0);
            vector<int> num(26, -1);
            bool ok = true;
            for (int i = n - 1, r = p; i >= 0; i--) {
                int cur = r % 10;
                r /= 10;
                if (c[cur] != 0 && num[s[i] - 'a'] != -1) {
                    if (c[cur] != s[i] || num[s[i] - 'a'] != cur) {
                        ok = false;
                        break;
                    }
                } else if (c[cur] == 0 && num[s[i] - 'a'] == -1) {
                    c[cur] = s[i];
                    num[s[i] - 'a'] = cur;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) return p;
        }
        return -1;
    };

    cout << calc() << '\n';
}