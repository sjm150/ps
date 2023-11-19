#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int cnts[5001];
int minm[5001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(cnts, cnts + 5001, 0);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a < 5001) cnts[a]++;
        }
        int mex = 0;
        while (cnts[mex]) mex++;
        minm[mex] = 0;
        for (int i = mex - 1; i >= 0; i--) {
            minm[i] = (cnts[i] - 1) * mex + i;
            for (int j = i + 1; j < mex; j++) minm[i] = min(minm[i], (cnts[i] - 1) * j + i + minm[j]);
        }
        cout << minm[0] << '\n';
    }
}