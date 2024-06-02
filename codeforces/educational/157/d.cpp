#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];

    vector<int> xsum(n);
    xsum[0] = 0;
    for (int i = 1; i < n; i++) xsum[i] = xsum[i - 1] ^ a[i - 1];

    vector<int> bcnt;
    for (int i = n - 1; i; i /= 2) {
        bcnt.push_back(0);
    }
    for (int i = 1; i < n; i++) {
        int cur = i;
        for (int j = 0; cur; j++, cur /= 2) {
            if (cur % 2) bcnt[j]++;
        }
        cur = xsum[i];
        for (int j = 0; cur; j++, cur /= 2) {
            if (cur % 2) bcnt[j]--;
        }
    }

    int b = 0, bit = 1;
    for (int i = 0; i < bcnt.size(); i++, bit <<= 1) if (bcnt[i]) b |= bit;
    
    for (int x: xsum) cout << (x ^ b) << ' ';
    cout << '\n';
}