#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    int y = 1;
    for (; y * y < n; y++) ;
    for (; y; y--) {
        if (n % y == 0) break;
    }
    
    int x = n / y;
    if (x < y) swap(x, y);
    vector<int> nl = {1};
    vector<pair<int, int>> edges;
    for (int i = 2; i <= x; i++) edges.emplace_back(i - 1, i);
    edges.emplace_back(x, x + 1);
    if (y > 1) {
        for (int i = 1; i < y; i++) edges.emplace_back(x + 1 - i, x + 1 + i);
    }

    assert(edges.size() == x + y - 1);
    cout << x + y << '\n';
    for (auto [a, b]: edges) cout << a << ' ' << b << '\n';
}