#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

vector<string> strs;
int n, k;
int rs[15], bases[15];
ll cnts[1 << 15][100];

void init(string& s, int i) {
    int &r = rs[i], &base = bases[i];
    r = 0, base = 1;
    for (char c: s) {
        r = (10 * r + c - '0') % k;
        base = (10 * base) % k;
    }
}

ll getcnt(int bm, int r) {
    queue<pi> q;
    vector<bool> pshd(1 << n, false);
    for (int i = 0; i < n; i++) {
        int bm = 1 << i;
        cnts[bm][rs[i]] = 1;
        q.emplace(bm, rs[i]);
    }
    while (!q.empty()) {
        auto [bm, r] = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            int b = 1 << i;
            if (bm & b) continue;
            int nbm = bm | b;
            int nr = (r * bases[i] + rs[i]) % k;
            if (cnts[nbm][nr] == 0) q.emplace(nbm, nr);
            cnts[nbm][nr] += cnts[bm][r];
        }
    }
    return cnts[(1 << n) - 1][0];
}

ll fact(int x) {
    ll f = 1;
    while (x) f *= x--;
    return f;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    strs = vector<string>(n);
    for (int i = 0; i < n; i++) cin >> strs[i];
    cin >> k;
    for (int i = 0; i < n; i++) init(strs[i], i);

    ll tot = fact(n);
    ll cnt = getcnt((1 << n) - 1, 0);
    ll g = gcd(tot, cnt);
    cout << cnt / g << '/' << tot / g << '\n';
}