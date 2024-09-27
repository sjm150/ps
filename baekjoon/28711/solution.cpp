#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> ans;
    while (n--) {
        string s; cin >> s;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            if ('a' <= s[i] && s[i] <= 'z') continue;
            int j = i + 1;
            while (j < sz && ('0' <= s[j] && s[j] <= '9')) j++;
            while (i < j - 1 && s[i] == '0') i++;
            ans.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    sort(ans.begin(), ans.end(), [](string &a, string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for (auto &a: ans) cout << a << '\n';
}