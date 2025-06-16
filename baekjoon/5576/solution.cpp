#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w[10], k[10];
    for (int &w: w) cin >> w;
    for (int &k: k) cin >> k;
    sort(w, w + 10);
    sort(k, k + 10);
    cout << accumulate(w + 7, w + 10, 0) << ' ' << accumulate(k + 7, k + 10, 0) << '\n';
}