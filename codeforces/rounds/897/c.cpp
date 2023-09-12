#include <bits/stdc++.h>
using namespace std;

int s[100000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> s[i];
        int mex = 0;
        while (mex < n && mex == s[mex]) mex++;
        int y;
        cout << mex << endl;
        cin >> y;
        while (y >= 0) {
            cout << y << endl;
            cin >> y;
        }
        if (y == -1) continue;
        else return 0;
    }
}