#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    auto solve = [&]() {
        for (int i = 0; i < int(s.size()); i++) {
            if ((s[i] == t[i]) != (n % 2 == 0)) return false;
        }
        return true;
    };
    cout << "Deletion " << (solve() ? "succeeded\n" : "failed\n");
}