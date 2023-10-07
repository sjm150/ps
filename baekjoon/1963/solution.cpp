#include <bits/stdc++.h>
using namespace std;

vector<bool> get_prm(int n) {
    vector<bool> prm(n + 1, true);
    prm[0] = prm[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!prm[i]) continue;
        for (int j = i * i; j <= n; j += i) prm[j] = false;
    }
    return prm;
}

bool solve(int s, int e, vector<int>& dst, vector<bool>& prm) {
    queue<int> q;
    fill(dst.begin(), dst.end(), -1);
    dst[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == e) return true;
        for (int i = 1; i <= 1000; i *= 10) {
            int base = cur / i / 10 * i * 10 + cur % i;
            for (int j = 0; j < 10; j++) {
                int nxt = base + j * i;
                if (!prm[nxt] || dst[nxt] >= 0 || nxt < 1000 || nxt >= 10000) continue;
                dst[nxt] = dst[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto prm = get_prm(9999);
    vector<int> dst(10000);
    int t; cin >> t;
    while (t--) {
        int s, e; cin >> s >> e;
        if (solve(s, e, dst, prm)) cout << dst[e] << '\n';
        else cout << "Impossible\n";
    }
}