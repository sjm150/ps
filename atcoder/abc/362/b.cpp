#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int xa, ya; cin >> xa >> ya;
    int xb, yb; cin >> xb >> yb;
    int xc, yc; cin >> xc >> yc;
    auto sqr = [&](int x) { return x * x; };
    int l[] = {sqr(xa - xb) + sqr(ya - yb), sqr(xb - xc) + sqr(yb - yc), sqr(xc - xa) + sqr(yc - ya)};
    sort(l, l + 3);
    cout << (l[0] + l[1] == l[2] ? "Yes\n" : "No\n");
}