#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cov = -1;
                for (int k = i; k <= j; k++) {
                    if (s[k] == '1' && cov < k) {
                        sum++;
                        cov = k + 2;
                    }
                }
            }
        }

        cout << sum << '\n';
    }
}