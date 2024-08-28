#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string k = "     ";
    for (auto &c: k) cin >> c;
    sort(k.begin(), k.end());
    vector<int> s;
    do {
        if (k[0] == '0') continue;
        s.push_back(stoi(k));
    } while (next_permutation(k.begin(), k.end()));
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) continue;
            for (int k = j + 1; k < n; k++) {
                if (s[j] == s[k]) continue;
                if (binary_search(s.begin() + k + 1, s.end(), s[i] + s[j] + s[k])) ans++;
            }
        }
    }
    cout << ans << '\n';
}