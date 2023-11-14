#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<bool> smt(31);
    for (int i = 0; i < 28; i++) {
        int n; cin >> n;
        smt[n] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (!smt[i]) cout << i << '\n';
    }
}