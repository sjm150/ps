#include <iostream>
#include <tuple>

using namespace std;

pair<int, int> get_idx(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 0: return {1, 1};
            case 1: return {1, 2};
            case 2: return {2, 2};
            case 3: return {2, 1};
            default: return {0, 0};
        }
    } else {
        int mod = n * n / 4;
        auto res = get_idx(n / 2, m % mod);
        switch (m / mod) {
            case 0: return {res.second, res.first};
            case 1: return {res.first, res.second + n / 2};
            case 2: return {n / 2 + res.first, res.second + n / 2};
            case 3: return {n + 1 - res.second, n / 2 + 1 - res.first};
            default: return {0, 0};
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int x, y;
    tie(x, y) = get_idx(n, m - 1);
    cout << x << ' ' << y << '\n';
}