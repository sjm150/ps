#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end());
    vector<bool> dead(n, false);
    int mx = *max_element(a.begin(), a.end());

    vector<int> cnt(mx + 1);
    int j = 0, c = 1;
    for (int i = 0; i <= mx; i++) {
        while (j < n && ord[j].first == i) {
            auto [s, idx] = ord[j++];
            dead[idx] = true;
            bool alld = true, alla = true;
            if (idx == 0 || dead[idx - 1]) alla = false;
            else alld = false;
            if (idx == n - 1 || dead[idx + 1]) alla = false;
            else alld = false;
            if (alld) c--;
            else if (alla) c++;
        }
        cnt[i] = c;
    }

    for (int i = 1; i <= mx; i++) {
        long long sum = 0;
        for (int j = 0; j < mx; j += i) sum += cnt[j];
        cout << sum << ' ';
    }
    cout << '\n';
}