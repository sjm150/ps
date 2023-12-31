#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int bb[2][3] = {{1, 6, 9}, {9, 6, 1}};
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        int zcnt = n - 3;
        int ccnt = zcnt / 2 + 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < ccnt; j++) {
                cout << bb[i][0];
                for (int k = 0; k < j; k++) cout << 0;
                cout << bb[i][1];
                for (int k = 0; k < j; k++) cout << 0;
                cout << bb[i][2];
                for (int k = 2 * j; k < zcnt; k++) cout << 0;
                cout << '\n';
            }
        }
        cout << 196;
        for (int i = 0; i < zcnt; i++) cout << 0;
        cout << '\n';
    }
}