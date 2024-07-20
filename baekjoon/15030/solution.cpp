#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string w; cin >> w;
    int n = w.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int mni = i;
        for (int j = i; j < n; j++) {
            if (w[mni] > w[j]) mni = j;
        }
        if (i != mni) {
            swap(w[i], w[mni]);
            ans.emplace_back(mni + 1, i + 1);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto [a, b]: ans) cout << a << ' ' << b << '\n';
}