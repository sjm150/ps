#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n;
        cin >> a >> b;

        int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                if (a[i] == '0') o++;
                if (b[i] == '0') e++;
            } else {
                if (a[i] == '0') e++;
                if (b[i] == '0') o++;
            }
        }

        cout << (e >= (n + 1) / 2 && o >= n / 2 ? "YES\n" : "NO\n");
    }
}