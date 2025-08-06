#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w, n;
    cin >> w >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    auto solve = [&]() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] - (i - 4 < 0 ? 0 : a[i - 4]);
            if (sum > w) return i;
        }
        return n;
    };
    cout << solve() << '\n';
}