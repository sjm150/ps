#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mn = 5;
    for (int i = 0; i <= n - 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) cnt += s[i + j] != "eagle"[j];
        mn = min(mn, cnt);
    }
    cout << mn << '\n';
}