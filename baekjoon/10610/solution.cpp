#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string line; cin >> line;
    int sum = 0;
    for (char c: line) {
        sum += c - '0';
        cnt[c - '0']++;
    }
    if (cnt[0] > 0 && sum % 3 == 0) {
        for (int i = 9; i >= 0; i--) {
            while (cnt[i]--) cout << i;
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}