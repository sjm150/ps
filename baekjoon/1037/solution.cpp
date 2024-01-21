#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int mind = 1e6, maxd = 2;
    while (n--) {
        int d; cin >> d;
        if (mind > d) mind = d;
        if (maxd < d) maxd = d;
    }
    cout << mind * maxd << '\n';
}