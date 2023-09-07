#include <bits/stdc++.h>
using namespace std;

int a[100001], c[100001];
int indeg[100001];
bool del[100001];

void del_dfs(int cur) {
    cout << cur << ' ';
    del[cur] = true;
    indeg[a[cur]]--;
    if (!del[a[cur]] && indeg[a[cur]] == 0) del_dfs(a[cur]);
}

int min_cst(int s, int cur) {
    if (a[cur] == s) return cur;
    int m = min_cst(s, a[cur]);
    if (c[cur] < c[m]) return cur;
    else return m;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(indeg, indeg + n + 1, 0);
        fill(del, del + n + 1, false);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            indeg[a[i]]++;
        }
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            if (!del[i] && indeg[i] == 0) del_dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            if (del[i]) continue;
            int m = min_cst(i, i);
            del_dfs(a[m]);
        }
        cout << '\n';
    }
}