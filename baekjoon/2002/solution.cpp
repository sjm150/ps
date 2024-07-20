#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    map<string, int> idx;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        idx[s] = i;
    }
    int cnt = 0, mex = 0;
    vector<bool> psd(n, false);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = idx[s];
        if (x != mex) cnt++;
        psd[x] = true;
        while (mex < n && psd[mex]) mex++;
    }
    cout << cnt << '\n';
}