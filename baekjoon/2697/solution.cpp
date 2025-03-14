#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a; cin >> a;
        int n = a.size();
        map<int, int> idx;
        bool prnt = false;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i] - '0';
            auto it = idx.upper_bound(x);
            if (it != idx.end()) {
                swap(a[i], a[it->second]);
                sort(a.begin() + i + 1, a.end());
                cout << a << '\n';
                prnt = true;
                break;
            } else {
                it = idx.find(x);
                if (it == idx.end()) idx[x] = i;
            }
        }
        if (!prnt) cout << "BIGGEST\n";
    }
}