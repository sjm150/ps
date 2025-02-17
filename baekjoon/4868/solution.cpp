#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<string> w;
    string s;
    while (cin >> s) w.push_back(s);
    sort(w.begin(), w.end(), [](string &a, string &b) { return a.size() < b.size(); });

    int sz = w.size();
    vector<int> len(sz, 1), pre(sz, -1);
    map<vector<int>, int> idx;
    for (int i = 0; i < sz; i++) {
        vector<int> cnt(26, 0);
        for (char c: w[i]) cnt[c - 'a']++;
        idx[cnt] = i;
        for (int j = 0; j < 26; j++) {
            if (!cnt[j]) continue;
            cnt[j]--;
            auto it = idx.find(cnt);
            if (it != idx.end() && len[it->second] >= len[i]) {
                len[i] = len[it->second] + 1;
                pre[i] = it->second;
            }
            cnt[j]++;
        }
    }

    function<void(int)> prnt = [&](int cur) {
        if (pre[cur] >= 0) prnt(pre[cur]);
        cout << w[cur] << '\n';
    };
    prnt(max_element(len.begin(), len.end()) - len.begin());
}