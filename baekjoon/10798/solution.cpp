#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<string> ss(5);
    int maxl = 0;
    for (int i = 0; i < 5; i++) {
        cin >> ss[i];
        maxl = max(maxl, int(ss[i].size()));
    }
    for (int j = 0; j < maxl; j++) {
        for (int i = 0; i < 5; i++) {
            if (ss[i].size() <= j) continue;
            cout << ss[i][j];
        }
    }
    cout << '\n';
}