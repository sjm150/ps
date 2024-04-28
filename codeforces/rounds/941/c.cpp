#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        for (int i = n - 1; i; i--) a[i] -= a[i - 1];

        vector<bool> win(n, false);
        int i = n - 1;
        while (!a[i]) i--;
        bool nxt = win[i] = true;
        for (i--; i >= 0; i--) {
            if (a[i] == 0) continue;
            if (a[i] == 1) win[i] = !nxt;
            else win[i] = true;
            nxt = win[i];
        }

        cout << (win[0] ? "Alice\n" : "Bob\n");
    }
}