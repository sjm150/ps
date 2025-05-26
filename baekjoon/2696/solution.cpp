#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> bq;
        priority_queue<int> sq;
        for (int a: a) {
            if (bq.empty() || bq.top() < a) {
                bq.push(a);
                if (bq.size() > sq.size() + 1) {
                    sq.push(bq.top());
                    bq.pop();
                }
            } else {
                sq.push(a);
                if (sq.size() > bq.size()) {
                    bq.push(sq.top());
                    sq.pop();
                }
            }
            if (bq.size() != sq.size()) ans.push_back(bq.top());
        }

        cout << ans.size() << '\n';
        int cnt = 0;
        for (int a: ans) {
            cnt++;
            cout << a << (cnt % 10 ? ' ' : '\n');
        }
        if (cnt % 10) cout << '\n';
    }
}