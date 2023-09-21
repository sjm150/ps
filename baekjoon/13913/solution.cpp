#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;

int dst[MX];
int pre[MX];

bool oob(int x) {
    return x < 0 || MX <= x;
}

void print_back(int cur) {
    if (cur < 0) return;
    print_back(pre[cur]);
    cout << cur << ' ';
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    fill(dst, dst + MX, -1);
    fill(pre, pre + MX, -1);
    dst[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int nxts[3] = {cur - 1, cur + 1, 2 * cur};
        for (int nxt: nxts) {
            if (oob(nxt) || dst[nxt] >= 0) continue;
            dst[nxt] = dst[cur] + 1;
            pre[nxt] = cur;
            q.push(nxt);
        }
    }
    cout << dst[k] << '\n';
    print_back(k);
    cout << '\n';
}