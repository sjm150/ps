#include <iostream>
typedef long long lint;
using namespace std;

int kinds[30000];
int sel[3001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) cin >> kinds[i];
    sel[c]++;
    int total = 1;
    for (int i = 0; i < k; i++) {
        if (sel[kinds[i]] == 0) total++;
        sel[kinds[i]]++;
    }
    int maxt = total;
    int s = 0, e = k - 1;
    do {
        if (sel[kinds[s]] == 1) total--;
        sel[kinds[s]]--;
        s = (s + 1) % n;
        e = (e + 1) % n;
        if (sel[kinds[e]] == 0) total++;
        sel[kinds[e]]++;
        maxt = max(maxt, total);
    } while (s != 0);
    cout << maxt << '\n';
}