#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        char cur = '0';
        int z2o = 0, o2z = 0;
        for (char c: s) {
            if (c != cur) {
                (cur == '0' ? z2o : o2z)++;
                cur = c;
            }
        }
        if (z2o > 1 || o2z > 1) z2o -= 2;
        else if (o2z) o2z--;
        cout << n + z2o + o2z << '\n';
    }
}