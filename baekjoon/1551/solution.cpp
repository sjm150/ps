#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (i) {
            char c;
            cin >> c;
        }
        cin >> a[i];
    }

    while (k--) {
        for (int i = 0; i < a.size() - 1; i++) a[i] = a[i + 1] - a[i];
        a.pop_back();
    }
    cout << a[0];
    for (int i = 1; i < a.size(); i++) cout << ',' << a[i];
    cout << '\n';
}