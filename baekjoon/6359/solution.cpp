#include <bits/stdc++.h>
using namespace std;

vector<bool> open(101);
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) open[j] = !open[j];
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (open[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}