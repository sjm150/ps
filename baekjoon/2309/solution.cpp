#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n = 9;
    vector<int> h(n);
    for (int &h: h) cin >> h;
    sort(h.begin(), h.end());
    int sum = accumulate(h.begin(), h.end(), 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sum - h[i] - h[j] == 100) {
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    cout << h[k] << '\n';
                }
                return 0;
            }
        }
    }
}