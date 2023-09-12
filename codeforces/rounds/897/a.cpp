#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi ai[40000];
int ans[40000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            ai[i] = {a, i};
        }
        sort(ai, ai + n);
        for (int i = 0; i < n; i++) {
            auto [a, idx] = ai[i];
            ans[idx] = n - i;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}