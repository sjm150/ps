#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[9];
    for (int &a: a) cin >> a;
    int sum = accumulate(a, a + 9, 0);
    auto solve = [&]() {
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (sum - a[i] - a[j] == 100) return make_pair(i, j);
            }
        }
        assert(false);
    };
    auto exc = solve();
    for (int i = 0; i < 9; i++) {
        if (i != exc.first && i != exc.second) cout << a[i] << '\n';
    }
}