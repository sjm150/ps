#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string t, a;
    cin >> t >> a;
    auto solve = [&]() {
        for (int i = 0; i < n; i++) {
            if (t[i] == 'o' && a[i] == 'o') return true;
        }
        return false;
    };
    cout << (solve() ? "Yes\n" : "No\n");
}