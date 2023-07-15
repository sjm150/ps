#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int use[100];
bool con[101];
int ccon[101];
int nuse[101];
pair<int, int> del[101];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> use[i];
    int concnt = 0;
    int delcnt = 0;
    for (int i = 0; i < k; i++) {
        if (con[use[i]]) continue;
        if (concnt < n) {
            con[use[i]] = true;
            concnt++;
            continue;
        }
        int idx = 0;
        for (int j = 1; j <= k; j++) {
            if (!con[j]) continue;
            ccon[idx++] = j;
            nuse[j] = 500;
        }
        for (int j = i + 1; j < k; j++) {
            if (!con[use[j]]) continue;
            nuse[use[j]] = min(nuse[use[j]], j);
        }
        idx = 0;
        for (int j = 0; j < n; j++) del[idx++] = {nuse[ccon[j]], ccon[j]};
        sort(del, del + n, greater<pair<int, int>>());
        con[del[0].second] = false;
        con[use[i]] = true;
        delcnt++;
    }
    cout << delcnt << '\n';
}