#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int cnt[3] = {};
    for (int a: a) {
        int x = (1000 - a % 1000) % 1000;
        for (int i = 0; i < 3; i++) {
            cnt[i] += x % 10;
            x /= 10;
        }
    }
    for (int c: cnt) cout << c << ' ';
    cout << '\n';
}