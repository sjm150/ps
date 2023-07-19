#include <iostream>

using namespace std;

int l[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> l[i];
    int s = 1, e = 1000000001;
    while (s < e) {
        int mid = (s + e) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += l[i] / mid;
        if (cnt >= m) s = mid + 1;
        else e = mid;
    }
    cout << e - 1 << '\n';
}