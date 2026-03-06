#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const string a[] = {"ABCABCABCABC", "BABCBABCBABC", "CCAABBCCAABB"};
    const string id[] = {"Adrian", "Bruno", "Goran"};
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[3] = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) cnt[i] += s[j] == a[i][j % 12];
    }
    int mx = *max_element(cnt, cnt + 3);
    cout << mx << '\n';
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == mx) cout << id[i] << '\n';
    }
}