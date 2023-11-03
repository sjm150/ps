#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> score(n);
    for (int i = 0; i < n; i++) cin >> score[i];
    sort(score.begin(), score.end());
    cout << score[n - k] << '\n';
}