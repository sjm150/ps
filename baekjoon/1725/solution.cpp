#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> h(n + 1);
    h[0] = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];

    int maxa = 0;
    vector<int> stk;
    for (int i = 0; i <= n; i++) {
        while (stk.size() > 1 && h[stk.back()] > h[i]) {
            int j = stk.back(); stk.pop_back();
            maxa = max(maxa, h[j] * (i - stk.back() - 1));
        }
        stk.push_back(i);
    }
    while (stk.size() > 1) {
        int j = stk.back(); stk.pop_back();
        maxa = max(maxa, h[j] * (n - stk.back()));
    }

    cout << maxa << '\n';
}