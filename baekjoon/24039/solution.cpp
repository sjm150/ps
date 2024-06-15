#include <bits/stdc++.h>
using namespace std;

const int mx = 10000;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<bool> prm(mx, true);
    int lst = 0;
    for (int i = 2; i < mx; i++) {
        if (!prm[i]) continue;
        if (lst * i > n) {
            cout << lst * i << '\n';
            break;
        }
        for (int j = i * i; j < mx; j += i) prm[j] = false;
        lst = i;
    }
}