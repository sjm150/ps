#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> g(n);
    int avg = 0;
    for (int &g: g) {
        cin >> g;
        avg += g;
    }
    avg /= n;
    for (int &g: g) g -= avg;

    long long ans[2] = {0, 0};
    vector<int> gg = g;
    int tmp = 0;
    for (int l = 0; l < 2; l++) {
        for (int &g: gg) {
            ans[0] += tmp;
            if (tmp + g >= 0) {
                tmp += g;
                g = 0;
            } else {
                g += tmp;
                tmp = 0;
            }
        }
    }

    tmp = 0;
    for (int l = 0; l < 2; l++) {
        for (int i = n - 1; i >= 0; i--) {
            ans[1] += tmp;
            if (tmp + g[i] >= 0) {
                tmp += g[i];
                g[i] = 0;
            } else {
                g[i] += tmp;
                tmp = 0;
            }
        }
    }

    cout << min(ans[0], ans[1]) << '\n';
}