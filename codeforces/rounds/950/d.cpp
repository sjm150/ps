#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };

        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; i++) b[i] = gcd(a[i], a[i + 1]);

        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            if (b[i] > b[i + 1]) cnt++;
        }

        bool poss = false;
        for (int i = 1; i < n - 1; i++) {
            int tmp = 0;
            if (i >= 2 && b[i - 2] > b[i - 1]) tmp++;
            if (b[i - 1] > b[i]) tmp++;
            if (i <= n - 3 && b[i] > b[i + 1]) tmp++;
            if (tmp < cnt) continue;

            int g = gcd(a[i - 1], a[i + 1]);
            if (i >= 2 && b[i - 2] > g) continue;
            if (i <= n - 3 && g > b[i + 1]) continue;

            poss = true;
            break;
        }
        if (cnt == 1 && (b[0] > b[1] || b[n - 3] > b[n - 2])) poss = true;
        if (cnt == 0) poss = true;

        cout << (poss ? "YES\n" : "NO\n");
    }
}