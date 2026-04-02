#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n), nxt(n), pi(26, -1);
    iota(pre.begin(), pre.end(), 0);
    iota(nxt.begin(), nxt.end(), 0);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (pi[c] >= 0) {
            pre[i] = pi[c];
            nxt[pi[c]] = i;
        }
        pi[c] = i;
    }
    vector<int> dst(n, -1);
    queue<int> q;
    dst[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: {cur - 1, cur + 1, pre[cur], nxt[cur]}) {
            if (nxt < 0 || nxt >= n || dst[nxt] >= 0) continue;
            dst[nxt] = dst[cur] + 1;
            q.push(nxt);
        }
    }
    cout << dst[n - 1] << '\n';
}