#include <iostream>
typedef long long lint;
using namespace std;

int l[100001], r[100001];
int psin(int p, bool mr) {
    int cnt = 0;
    if (l[p] > 0) cnt += 1 + psin(l[p], false);
    if (r[p] > 0) cnt += 1 + psin(r[p], mr);
    if (!mr) cnt++;
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        cin >> l[p] >> r[p];
    }
    cout << psin(1, true) << '\n';
}