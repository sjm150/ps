#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int sz = n.size();
        for (int i = 1; i < sz; i++) {
            if (n[i - 1] > n[i]) {
                int idx = i;
                for (; idx < sz - 1; idx++) {
                    if (n[idx] < n[idx + 1]) break;
                }
                for (int j = idx + 1; j < sz; j++) n[j] = n[idx];
                break;
            }
        }
        cout << n << '\n';
    }
}