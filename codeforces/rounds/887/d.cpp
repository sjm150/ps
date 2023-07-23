#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[100000];
int ans[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            a[i] = {num, i};
        }
        sort(a, a + n);
        int s = 0, e = n - 1;
        int cur = n;
        int neg = 0, pst = 0;
        bool sw = a[0].first == 0;
        bool able = true;
        while (s <= e) {
            if (sw) {
                int num = a[s].first;
                if (num != pst) {
                    able = false;
                    break;
                }
                ans[a[s].second] = -cur;
                s++;
                neg++;
                while (s <= e && a[s].first == a[s - 1].first) {
                    ans[a[s].second] = -cur;
                    s++;
                    neg++;
                }
            } else {
                int num = a[e].first;
                if (num != n - neg) {
                    able = false;
                    break;
                }
                ans[a[e].second] = cur;
                e--;
                pst++;
                while (s <= e && a[e].first == a[e + 1].first) {
                    ans[a[e].second] = cur;
                    e--;
                    pst++;
                }
            }
            cur--;
            sw = !sw;
        }
        if (able) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << ans[i] << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}