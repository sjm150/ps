#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &h: h) cin >> h;
    auto sqr = [](int x) { return x * x; };
    int ans = 0;
    for (int i = 1; i < n; i++) ans += sqr(h[i - 1] - h[i]) + sqr(h[i - 1] + h[i]);
    cout << ans << '\n';
}