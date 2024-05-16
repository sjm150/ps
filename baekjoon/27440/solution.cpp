#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    map<ll, int> dst;
    queue<ll> q;
    dst[n] = 0;
    q.push(n);

    auto push = [&](ll nxt, int d) {
        if (nxt == 1) {
            cout << d << '\n';
            exit(0);
        } else if (dst.find(nxt) == dst.end()) {
            dst[nxt] = d;
            q.push(nxt);
        }
    };

    while (!q.empty()) {
        ll cur = q.front(); q.pop();
        int d = dst[cur] + 1;
        if (cur % 3 == 0) push(cur / 3, d);
        if (cur % 2 == 0) push(cur / 2, d);
        push(cur - 1, d);
    }

    cout << dst[1] << '\n';
}