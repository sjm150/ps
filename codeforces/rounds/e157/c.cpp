#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end(), [](const string& a, const string& b){ return a.length() > b.length(); });

    ll cnt = n;
    map<int, int> lm[6], rm[6];
    for (string& str: s) {
        int len = str.size();
        vector<int> diff(len + 1);
        diff[0] = 0;
        for (char c: str) diff[0] += c - '0';
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0';
            diff[i + 1] = diff[i] - 2 * digit;
        }

        if (lm[len].find(diff[0]) != lm[len].end()) cnt += lm[len][diff[0]];
        if (rm[len].find(diff[0]) != rm[len].end()) cnt += rm[len][diff[0]];
        for (int i = 0; i <= len; i++) {
            int dl = len - 2 * i;
            if (dl > 0 && diff[i] > 0) {
                if (rm[dl].find(diff[i]) != rm[dl].end()) rm[dl][diff[i]]++;
                else rm[dl][diff[i]] = 1;
            } else if (dl < 0 && diff[i] < 0) {
                if (lm[-dl].find(-diff[i]) != lm[-dl].end()) lm[-dl][-diff[i]]++;
                else lm[-dl][-diff[i]] = 1;
            }
        }
    }
    cout << cnt << '\n';
}