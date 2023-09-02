#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int lst[1000000], lidx;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    lst[lidx++] = a[0];
    for (int i = 1; i < n; i++) {
        int idx = lower_bound(lst, lst + lidx, a[i]) - lst;
        lst[idx] = a[i];
        if (idx == lidx) lidx++;
    }
    cout << lidx << '\n';
}