#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

bool adj[8][8];
void init_adj() {
    adj[0][1] = adj[0][2] = true;
    adj[1][0] = adj[1][2] = adj[1][3] = true;
    adj[2][0] = adj[2][1] = adj[2][3] = adj[2][4] = true;
    adj[3][1] = adj[3][2] = adj[3][4] = adj[3][5] = true;
    adj[4][2] = adj[4][3] = adj[4][5] = adj[4][7] = true;
    adj[5][3] = adj[5][4] = adj[5][6] = true;
    adj[6][5] = adj[6][7] = true;
    adj[7][4] = adj[7][6] = true;
}

unordered_map<int, ll> cache[8][8];
ll cnt(int from, int to, int d) {
    if (d == 1) {
        if (adj[from][to]) return 1;
        else return 0;
    }
    auto it = cache[from][to].find(d);
    if (it != cache[from][to].end()) return it->second;
    ll ret = 0;
    for (int i = 0; i < 8; i++) ret = (ret + cnt(from, i, d / 2) * cnt(i, to, d - d / 2)) % mod;
    cache[from][to][d] = ret;
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init_adj();
    int d; cin >> d;
    cout << cnt(0, 0, d) << '\n';
}