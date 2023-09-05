#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int n, comp;
int w[16][16];
int cache[16][65536];

bool incl(int vst, int v) {
    return (vst & (1 << v)) != 0;
}
int add(int vst, int v) {
    return (vst | (1 << v));
}

int dfs(int cur, int vst) {
    if (vst == comp) return w[cur][0];
    int& ret = cache[cur][vst];
    if (ret != 0) return ret;
    ret = inf;
    for (int nxt = 0; nxt < n; nxt++) {
        if (incl(vst, nxt)) continue;
        ret = min(ret, w[cur][nxt] + dfs(nxt, add(vst, nxt)));
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    comp = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
            if (w[i][j] == 0) w[i][j] = inf;
        }
    }
    cout << dfs(0, 1) << '\n';
}