#include <iostream>
#include <algorithm>

using namespace std;

const pair<int, int> s = {3, 1}, e = {11, 30};
pair<pair<int, int>, pair<int, int>> dur[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        dur[i] = {{m1, d1}, {m2, d2}};
    }
    sort(dur, dur + n);
    pair<int, int> last = s;
    pair<int, int> maxe = last;
    int idx = 0;
    int cnt = 0;
    while (last <= e) {
        if (idx == n) {
            cout << 0 << '\n';
            return 0;
        }
        while (idx < n && dur[idx].first <= last) {
            maxe = max(maxe, dur[idx].second);
            idx++;
        }
        if (last == maxe) {
            cout << 0 << '\n';
            return 0;
        }
        last = maxe;
        cnt++;
    }
    cout << cnt << '\n';
}