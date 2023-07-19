#include <iostream>

using namespace std;
typedef long long int lint;

int h[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> h[i];
    int s = 0, e = 1000000001;
    while (s < e) {
        int mid = (s + e) / 2;
        lint sum = 0;
        for (int i = 0; i < n; i++) sum += max(h[i] - mid, 0);
        if (sum >= m) s = mid + 1;
        else e = mid;
    }
    cout << e - 1 << '\n';
}