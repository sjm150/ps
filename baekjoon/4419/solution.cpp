#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> s(n);
    for (auto &s: s) getline(cin, s);
    vector<vector<int>> v;
    int x;
    while (cin >> x) {
        v.emplace_back(n);
        v.back()[0] = x - 1;
        for (int i = 1; i < n; i++) {
            cin >> v.back()[i];
            v.back()[i]--;
        }
    }

    int sz = v.size();
    vector<int> idx(sz, 0), cnt(n, 0);
    for (auto &v: v) cnt[v[0]]++;

    vector<bool> exl(n, false);
    while (*max_element(cnt.begin(), cnt.end()) * 2 < sz) {
        int mn = -1;
        for (int i = 0; i < n; i++) {
            if (!exl[i] && (mn < 0 || mn > cnt[i])) mn = cnt[i];
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] == mn) exl[i] = true;
        }
        if (find(exl.begin(), exl.end(), false) == exl.end()) break;
        for (int i = 0; i < sz; i++) {
            cnt[v[i][idx[i]]]--;
            while (exl[v[i][idx[i]]]) idx[i]++;
            cnt[v[i][idx[i]]]++;
        }
    }

    int mx = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < n; i++) {
        if (cnt[i] == mx) cout << s[i] << '\n';
    }
}