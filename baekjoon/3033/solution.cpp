#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;

    vector<int> sa(n), pos(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }
    for (int d = 1; ; d *= 2) {
        auto cmp = [&](int a, int b) {
            if (pos[a] != pos[b]) return pos[a] < pos[b];
            a += d, b += d;
            return a < n && b < n ? pos[a] < pos[b] : a > b;
        };
        sort(sa.begin(), sa.end(), cmp);
        auto np = pos;
        np[sa[0]] = 0;
        for (int i = 1; i < n; i++) np[sa[i]] = np[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        swap(np, pos);
        if (pos[sa[n - 1]] == n - 1) break;
    }

    vector<int> lcp(n - 1);
    for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
        if (pos[i] == n - 1) continue;
        for (int j = sa[pos[i] + 1]; max(i, j) + k < n && s[i + k] == s[j + k];) k++;
        lcp[pos[i]] = k;
    }

    cout << (lcp.empty() ? 0 : *max_element(lcp.begin(), lcp.end())) << '\n';
}