#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int mxl = 0;
        for (int i = 0; i < b.size(); i++) {
            int l = 0;
            for (int j = 0; j < a.size() && i + l < b.size(); j++) {
                if (a[j] == b[i + l]) l++;
            }
            mxl = max(mxl, l);
        }
        cout << a.size() + b.size() - mxl << '\n';
    }
}