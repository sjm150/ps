#include <iostream>
#include <vector>
using namespace std;

int cnt[50001];
vector<int> sqrs;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i * i <= n; i++) sqrs.push_back(i * i);
    for (int i = 1; i <= n; i++) {
        cnt[i] = i;
        int idx = 0;
        while (idx < sqrs.size() && (i - sqrs[idx]) >= 0) {
            cnt[i] = min(cnt[i], cnt[i - sqrs[idx]] + 1);
            idx++;
        }
    }
    cout << cnt[n] << '\n';
}