#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        auto ss = stringstream(s);
        vector<int> a;
        int cur;
        while (ss >> cur) a.push_back(cur);
        int sz = a.size(), ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) ans = max(ans, gcd(a[i], a[j]));
        }
        cout << ans << '\n';
    }
}