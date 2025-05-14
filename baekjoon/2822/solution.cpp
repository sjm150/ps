#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    pi s[8];
    for (int i = 0; i < 8; i++) {
        int x; cin >> x;
        s[i] = {x, i};
    }
    sort(s, s + 8, greater<pi>());
    sort(s, s + 5, [](pi &a, pi &b) { return a.second < b.second; });
    vector<pi> res(s, s + 5);
    int sum = 0;
    for (auto &[x, i]: res) sum += x;
    cout << sum << '\n';
    for (auto &[x, i]: res) cout << i + 1 << ' ';
    cout << '\n';
}