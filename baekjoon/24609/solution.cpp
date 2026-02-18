#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int cur = 0, mn = 0;
    while (n--) {
        int x;
        cin >> x;
        cur += x;
        mn = min(mn, cur);
    }
    cout << -mn << '\n';
}