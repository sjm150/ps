#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        vector<int> cnt(10, 0);
        string s; cin >> s;
        for (char c: s) cnt[c - '0']++;
        for (int i = 9; i >= 0; i--) {
            for (int j = i; j < 10; j++) {
                if (cnt[j] > 0) {
                    cout << j;
                    cnt[j]--;
                    break;
                }
            }
        }
        cout << '\n';
    }
}