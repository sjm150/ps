#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    auto solve = [&]() {
        int c = (n - 1) * 2;
        int f = (n - 2) * (n - 1) / 2, b = (n - 1) * n / 2;
        return 1 * 35 + c * 28 + f * 21 + b * 14;
    };

    cout << solve() << '\n';
}