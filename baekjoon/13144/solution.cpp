#include <iostream>
using namespace std;
typedef long long ll;

int num[100000], used[100001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    int s = 0, e = 0;
    used[num[0]]++;
    bool overlap = false;
    ll cnt = 1;
    while (e < n) {
        if (!overlap) {
            e++;
            if (e == n) break;
            if (used[num[e]] > 0) overlap = true;
            else cnt += e - s + 1;
            used[num[e]]++;
        } else {
            if (used[num[s]] == 2) {
                overlap = false;
                cnt += e - s;
            }
            used[num[s]]--;
            s++;
        }
    }
    cout << cnt << '\n';
}