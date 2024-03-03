#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mi = 0;
        for (int i = 1; i < n; i++) {
            cout << "? " << mi << ' ' << mi << ' ' << i << ' ' << i << endl;
            char c; cin >> c;
            if (c == '<') mi = i;
        }

        int mj = 0;
        vector<int> js(1, 0);
        for (int i = 1; i < n; i++) {
            cout << "? " << mi << ' ' << mj << ' ' << mi << ' ' << i << endl;
            char c; cin >> c;
            if (c == '<') {
                mj = i;
                js = vector<int>(1, i);
            } else if (c == '=') {
                js.push_back(i);
            }
        }

        int minj = js[0];
        for (int i = 1; i < js.size(); i++) {
            cout << "? " << minj << ' ' << minj << ' ' << js[i] << ' ' << js[i] << endl;
            char c; cin >> c;
            if (c == '>') minj = js[i];
        }

        cout << "! " << mi << ' ' << minj << endl;
    }
}