#include <iostream>
#include <algorithm>

using namespace std;

int v[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    int minv = 2000000000;
    int mina = -1, minb = -1;
    for (int i = 0; i < n; i++) {
        int lb = lower_bound(v, v + n, -v[i]) - v;
        if (i != lb - 1 && lb > 0 && minv > abs(v[i] + v[lb - 1])) {
            mina = v[i], minb = v[lb - 1];
            minv = abs(mina + minb);
        }
        if (i != lb && lb < n && minv > abs(v[i] + v[lb])) {
            mina = v[i], minb = v[lb];
            minv = abs(mina + minb);
        }
    }
    cout << min(mina, minb) << ' ' << max(mina, minb) << '\n';
}