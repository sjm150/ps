#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int len[1000000];
int idx[1000000];
int pre[1000000];
int lidx, lst;

void print_back(int cur) {
    if (cur == -1) return;
    print_back(pre[cur]);
    cout << a[cur] << ' ';
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x = lower_bound(len, len + lidx, a[i]) - len;
        if (x == lidx) len[lidx++] = a[i];
        else len[x] = a[i];
        idx[x] = i;
        if (x > 0) pre[i] = idx[x - 1];
        else pre[i] = -1;
    }
    cout << lidx << '\n';
    print_back(idx[lidx - 1]);
    cout << '\n';
}