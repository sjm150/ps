#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int s;
    cin >> s;
    vector<int> cnts;
    while (s) {
        int r = sqrt(2 * s);
        while (r * (r + 1) / 2 > s) r--;
        cnts.push_back(r);
        s -= r * (r + 1) / 2;
    }
    int sz = cnts.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < cnts[i]; j++) cout << char('a' + (i % 26));
    }
    cout << '\n';
}