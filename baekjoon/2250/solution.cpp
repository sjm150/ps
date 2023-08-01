#include <iostream>
using namespace std;

int l[10001], r[10001];
int levmin[10001], levmax[10001];
int dfs(int p, int lev, int col) {
    int cur = col + 1;
    if (l[p] != -1) cur = dfs(l[p], lev + 1, col) + 1;
    if (levmin[lev] == 0) {
        levmin[lev] = levmax[lev] = cur;
    } else {
        levmin[lev] = min(levmin[lev], cur);
        levmax[lev] = max(levmax[lev], cur);
    }
    if (r[p] != -1) cur = dfs(r[p], lev + 1, cur);
    return cur;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        cin >> l[p] >> r[p];
    }
    int root = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (l[i] != -1) root -= l[i];
        if (r[i] != -1) root -= r[i];
    }
    dfs(root, 1, 0);
    int lev = 1;
    int maxl = 1;
    int maxw = 1;
    while (levmin[lev]) {
        int w = levmax[lev] - levmin[lev] + 1;
        if (w > maxw) {
            maxw = w;
            maxl = lev;
        }
        lev++;
    }
    cout << maxl << ' ' << maxw << '\n';
}