#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, r; cin >> n;
        vector<int> p(n), pre;
        int i = 2;
        for (; i < n; i++) {
            cout << "? " << 1 << ' ' << i << endl;
            cin >> r;
            if (r) {
                p[i] = 0;
                pre.push_back(i);
            } else {
                break;
            }
        }
        if (i < n) {
            vector<int> npre;
            p[i] = 1;
            npre.push_back(i++);
            while (i < n) {
                for (int x: pre) {
                    if (i == n) break;
                    cout << "? " << x << ' ' << i << endl;
                    cin >> r;
                    if (r) {
                        continue;
                    } else {
                        p[i] = x;
                        npre.push_back(i);
                        i++;
                    }
                }
                swap(pre, npre);
                npre.clear();
            }
        }
        cout << '!';
        for (int i = 1; i < n; i++) cout << ' ' << p[i];
        cout << endl;
    }
}