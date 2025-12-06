#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> l(n);
    for (int &l: l) cin >> l;

    int sz = accumulate(l.begin(), l.end(), 0);
    vector<bool> poss(sz + 1, false);
    poss[0] = true;
    for (int l: l) {
        for (int i = sz; i >= l; i--) {
            if (poss[i - l]) poss[i] = true;
        }
    }

    long long cnt = accumulate(poss.begin(), poss.end(), 0);
    cout << cnt * (sz + 1) - cnt * (cnt - 1) / 2 << '\n';
}