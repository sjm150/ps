#include <iostream>
#include <algorithm>
typedef long long lint;
using namespace std;

int h[600];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);
    int mind = INT32_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = h[j] - h[i];
            int l = 0;
            if (l == i) l++;
            if (l == j) l++;
            int r = l + 1;
            if (r == i) r++;
            if (r == j) r++;
            do {
                int curr = h[r] - h[l];
                mind = min(mind, abs(diff - curr));
                if (curr == diff) {
                    cout << 0 << '\n';
                    return 0;
                } else if (curr < diff) {
                    r++;
                    if (r == i) r++;
                    if (r == j) r++;
                } else {
                    l++;
                    if (l == i) l++;
                    if (l == j) l++;
                    if (r == l) {
                        r++;
                        if (r == i) r++;
                        if (r == j) r++;
                    }
                }
            } while (r < n);
        }
    }
    cout << mind << '\n';
}