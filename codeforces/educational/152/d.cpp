#include <bits/stdc++.h>
using namespace std;

int a[200000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = 0, e = 0;
    int cnt = 0;
    bool exst2 = a[0] == 2;
    while (e < n) {
        e++;
        if (e >= n) {
            cnt++;
            break;
        }
        if (a[e] == 2) exst2 = true;
        if (a[e] == 0) {
            cnt++;
            if (exst2 || a[s] != 0) {
                e++;
                if (e >= n) break;
            }
            s = e;
            exst2 = a[s] == 2;
        }
    }
    cout << cnt << '\n';
}