#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int pre = 0, cnt = 0;
        for (int &a: a) {
            cin >> a;
            if (!pre && a) cnt++;
            pre = a;
        }
        cout << min(cnt, 2) << '\n';
    }
}