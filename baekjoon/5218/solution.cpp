#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        cout << "Distances: ";
        for (int i = 0; i < n; i++) cout << (t[i] - s[i] + 26) % 26 << ' ';
        cout << '\n';
    }
}