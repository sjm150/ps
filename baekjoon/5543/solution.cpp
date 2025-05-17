#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(a, min(b, c)) + min(d, e) - 50 << '\n';
}