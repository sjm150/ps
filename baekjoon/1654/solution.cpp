#include <iostream>

using namespace std;

int len[10000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int k, n;
    cin >> k >> n;
    long long int s = 0, e = 0;
    for (int i = 0; i < k; i++) {
        cin >> len[i];
        e = max(e, (long long int) len[i]);
    }
    e++;
    while (s < e) {
        long long int m = (s + e) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += len[i] / m;
        if (cnt < n) e = m ;
        else s = m + 1;
    }
    cout << s - 1 << '\n';
}