#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    stack<ll> grp;
    grp.push(-1);
    while (n--) {
        int p, s; cin >> p >> s;
        ll pp = p + ll(s) * t;
        while (grp.top() >= pp) grp.pop();
        grp.push(pp);
    }
    cout << grp.size() - 1 << '\n';
}