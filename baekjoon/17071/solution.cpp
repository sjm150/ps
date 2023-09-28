#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int MX = 500001;

bool poss[2][MX];
queue<int> q[2];
int cur = 0, nxt = 1;

bool oob(int x) {
    return x < 0 || MX <= x;
}

void swap() {
    while (!q[cur].empty()) {
        int x = q[cur].front(); q[cur].pop();
        for (int nx: {x - 1, x + 1, x * 2}) {
            if (oob(nx) || poss[nxt][nx]) continue;
            poss[nxt][nx] = true;
            q[nxt].push(nx);
        }
    }
    cur = 1 - cur;
    nxt = 1 - nxt;
}

int solve(int n, int k) {
    if (n == k) return 0;
    poss[cur][n] = true;
    q[cur].push(n);
    for (int t = 1; k + t < MX; t++) {
        swap();
        k += t;
        if (poss[cur][k]) return t;
    }
    return -1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    cout << solve(n, k) << '\n';
}