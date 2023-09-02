#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[40];
void select(int i, int e, int sum, vector<int>& sums) {
    if (i == e) {
        sums.push_back(sum);
        return;
    }
    select(i + 1, e, sum, sums);
    select(i + 1, e, sum + num[i], sums);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    vector<int> fsum, bsum;
    select(0, n / 2, 0, fsum);
    select(n / 2, n, 0, bsum);
    sort(fsum.begin(), fsum.end());
    ll scnt = 0;
    for (int bs: bsum) {
        scnt += upper_bound(fsum.begin(), fsum.end(), s - bs) - lower_bound(fsum.begin(), fsum.end(), s - bs);
    }
    if (s == 0) scnt--;
    cout << scnt << '\n';
}