#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &p: p) cin >> p;

    int mx = *max_element(p.begin(), p.end());
    vector<int> nim(mx + 1, 0);
    nim[0] = nim[1] = 0;
    for (int i = 2; i <= mx; i++) {
        vector<bool> ext(mx + 1, false);
        for (int j = 1; j < i; j++) ext[nim[(i % j)] ^ nim[(i / j % 2 ? j : 0)]] = true;
        while (ext[nim[i]]) nim[i]++;
    }

    int res = 0;
    for (int p: p) res ^= nim[p];
    cout << (res ? "First\n" : "Second\n");
}