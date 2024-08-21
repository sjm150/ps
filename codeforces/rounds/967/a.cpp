#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), cnt(n + 1, 0);
        for (int &a: a) {
            cin >> a;
            cnt[a]++;
        }
        cout << n - *max_element(cnt.begin(), cnt.end()) << '\n';
    }
}