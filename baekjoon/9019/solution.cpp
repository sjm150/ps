#include <iostream>
#include <queue>
using namespace std;

int d(int n) {
    return 2 * n % 10000;
}
int s(int n) {
    return n == 0 ? 9999 : n - 1;
}
int l(int n) {
    return (n * 10 + n / 1000) % 10000;
}
int r(int n) {
    return n / 10 + n % 10 * 1000;
}

int dst[10000];
int pre[10000];

void print(int cur, int nxt) {
    if (cur == -1) return;
    print(pre[cur], cur);
    if (nxt == d(cur)) cout << 'D';
    else if (nxt == s(cur)) cout << 'S';
    else if (nxt == l(cur)) cout << 'L';
    else cout << 'R';
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        fill(dst, dst + 10000, -1);
        queue<int> q;
        dst[a] = 0;
        pre[a] = -1;
        q.push(a);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nxt;
                if (i == 0) nxt = d(cur);
                else if (i == 1) nxt = s(cur);
                else if (i == 2) nxt = l(cur);
                else nxt = r(cur);
                if (dst[nxt] < 0) {
                    dst[nxt] = dst[cur] + 1;
                    pre[nxt] = cur;
                    q.push(nxt);
                }
            }
        }
        print(pre[b], b);
        cout << '\n';
    }
}