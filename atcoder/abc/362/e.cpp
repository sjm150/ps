#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    cout << n << ' ';
    if (n == 1) return 0;
    vector<map<int, int>> dcnt(n);
    int sum = 0;
    for (int i = n - 1; i; i--) {
        for (int j = 0; j < i; j++) {
            dcnt[i][a[i] - a[j]]++;
            sum++;
        }
    }
    cout << sum << ' ';

    for (int l = 3; l <= n; l++) {
        sum = 0;
        for (int i = n - 1; i; i--) {
            dcnt[i].clear();
            for (int j = 0; j < i; j++) {
                for (auto &[d, c]: dcnt[j]) {
                    if (d == a[i] - a[j]) {
                        int &dd = dcnt[i][d];
                        dd = (dd + c) % mod;
                        sum = (sum + c) % mod;
                    }
                }
            }
        }
        cout << sum << ' ';
    }
    cout << '\n';
}