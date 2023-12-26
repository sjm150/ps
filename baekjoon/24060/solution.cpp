#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a[2];
int s, ans = -1;

void mergesort(int l, int r, int tar) {
    if (l == r - 1) return;
    int src = 1 - tar;
    int m = (l + r + 1) / 2;
    mergesort(l, m, src);
    mergesort(m, r, src);

    int i = l, j = m, idx = l;
    while (i < m && j < r) {
        if (a[src][i] <= a[src][j]) a[tar][idx++] = a[src][i++];
        else a[tar][idx++] = a[src][j++];
        s++;
        if (s == k) ans = a[tar][idx - 1];
    }
    while (i < m) {
        a[tar][idx++] = a[src][i++];
        s++;
        if (s == k) ans = a[tar][idx - 1];
    }
    while (j < r) {
        a[tar][idx++] = a[src][j++];
        s++;
        if (s == k) ans = a[tar][idx - 1];
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;
    a[0] = a[1] = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
        a[1][i] = a[0][i];
    }
    mergesort(0, n, 0);
    cout << ans << '\n';
}