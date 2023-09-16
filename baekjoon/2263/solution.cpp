#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int v[MX + 1];
int pst[MX + 1];
int l[MX + 1], r[MX + 1];

int parse(int lim, int cur) {
    int mini = cur;
    if (v[pst[lim]] >= v[pst[cur - 1]]) return mini;
    if (v[pst[cur]] < v[pst[cur - 1]]) {
        r[cur] = cur - 1;
        mini = parse(cur, cur - 1);
    }
    if (v[pst[lim]] < v[pst[mini - 1]]) {
        l[cur] = mini - 1;
        mini = parse(lim, mini - 1);
    }
    return mini;
}

void print(int cur) {
    cout << pst[cur] << ' ';
    if (l[cur]) print(l[cur]);
    if (r[cur]) print(r[cur]);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[x] = i;
    }
    for (int i = 1; i <= n; i++) cin >> pst[i];
    parse(0, n);
    print(n);
    cout << '\n';
}