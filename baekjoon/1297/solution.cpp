#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int d, h, w;
    cin >> d >> h >> w;
    auto x = sqrt(h * h + w * w);
    cout << int(d * sqrt(h * h) / x) << ' ' << int(d * sqrt(w * w) / x) << '\n';
}