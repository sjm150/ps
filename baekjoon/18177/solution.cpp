#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    for (int i = 1 << 29; i; i /= 2) {
        vector<int> na;
        int cnt = 0;
        for (int a: a) {
            if (a & i) {
                na.push_back(a);
                cnt++;
            }
        }
        if (cnt >= k) swap(a, na);
    }
    int ans = (1 << 30) - 1;
    for (int a: a) ans &= a;
    cout << ans << '\n';
}