#include <bits/stdc++.h>
using namespace std;

int cnts[100001];
void init_cnts() {
    for (int i = 1; i <= 100000; i++) {
        cnts[i] = 1;
        for (int j = 2; j * j <= i; j++) {
            int q = i / j;
            if (q * j != i) continue;
            if (q == j) cnts[i] += cnts[j];
            else cnts[i] += cnts[j] + cnts[q];
        }
    }
}

int stk[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init_cnts();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        stk[a]++;
    }
    int m; cin >> m;
    while (m--) {
        int l; cin >> l;
        int cnt = 0;
        for (int i = 1; i * i <= l; i++) {
            int q = l / i;
            if (q * i != l) continue;
            if (q == i) cnt += cnts[i] * stk[i];
            else cnt += cnts[i] * stk[q] + cnts[q] * stk[i];
        }
        cout << cnt << ' ';
    }
    cout << '\n';
}