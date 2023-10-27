#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;

int calc(int lhs, int op, int rhs) {
    if (op == 0) return lhs + rhs;
    else if (op == 1) return lhs - rhs;
    else if (op == 2) return lhs * rhs;
    else return lhs / rhs;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> p;
    for (int i = 0; i < 4; i++) {
        int x; cin >> x;
        while (x--) p.push_back(i);
    }

    int mina = inf, maxa = -inf;
    do {
        int res = a[0];
        for (int i = 0; i < p.size(); i++) res = calc(res, p[i], a[i + 1]);
        if (mina > res) mina = res;
        if (maxa < res) maxa = res;
    } while (next_permutation(p.begin(), p.end()));

    cout << maxa << '\n';
    cout << mina << '\n';
}