#include <iostream>
typedef long long lint;
using namespace std;

int a[200000];
int cnt[100001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = 0, e = -1;
    int dup = 0;
    int maxl = 0;
    do {
        if (dup <= k) maxl = max(maxl, e - s + 1);
        if (dup <= k) {
            e++;
            cnt[a[e]]++;
            dup = max(dup, cnt[a[e]]);
        } else {
            if (cnt[a[s]] == dup) dup--;
            cnt[a[s]]--;
            s++;
        }
    } while (e < n);
    cout << maxl << '\n';
}