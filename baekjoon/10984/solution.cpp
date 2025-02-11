#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        double sum = 0;
        while (n--) {
            int c; cin >> c;
            double s; cin >> s;
            cnt += c;
            sum += c * s;
        }
        cout << cnt << ' ' << sum / cnt << '\n';
    }
}