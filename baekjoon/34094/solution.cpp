#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    if (accumulate(a.begin(), a.end(), 0ll) == 0) {
        cout << 0 << '\n';
    } else {
        sort(a.begin(), a.end());
        int mx = 0;
        for (int a: a) {
            if (mx == a) mx++;
        }
        cout << mx + 1 << '\n';
    }
    for (int a: a) cout << a << ' ';
    cout << '\n';
}