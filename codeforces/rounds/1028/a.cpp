#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    };
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int g = 0;
        for (int a: a) g = gcd(a, g);
        for (int &a: a) a /= g;

        int mx = *max_element(a.begin(), a.end());
        vector<int> cnt(mx + 1, 1e9);
        for (int a: a) {
            for (int i = 2; i <= mx; i++) {
                int g = gcd(i, a);
                cnt[g] = min(cnt[g], cnt[i] + 1);
            }
            cnt[a] = 0;
        }

        int ocnt = count(a.begin(), a.end(), 1);
        cout << (ocnt ? n - ocnt : cnt[1] + n - 1) << '\n';
    }
}