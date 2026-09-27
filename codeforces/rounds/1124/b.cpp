#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 1000;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        for (int &a: a) {
            for (int i = 0; i < mx; i++) {
                int nxt = 0;
                for (int j = a; j; j /= 10) nxt += (j % 10) * (j % 10);
                a = nxt;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) cnt++;
            }
        }

        cout << cnt << '\n';
    }
}