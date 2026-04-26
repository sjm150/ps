#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    auto query = [&](vector<int> &q) {
        cout << "? ";
        for (int q: q) cout << q << ' ';
        cout << endl;
        int r;
        cin >> r;
        return r;
    };
    auto answer = [](const vector<int> &p) {
        cout << "! ";
        for (int p: p) cout << p << ' ';
        cout << endl;
    };
    if (n == 1) {
        answer({1});
        return 0;
    }

    vector<int> q(n), ans(n);
    iota(q.begin(), q.end(), 1);
    ans[0] = 0;
    swap(q[1], q[n - 1]);

    int v1 = query(q);
    swap(q[0], q[1]);
    int v2 = query(q);
    swap(q[0], q[1]);
    ans[1] = (v2 - v1) / 2;

    for (int i = 2; i < n; i++) {
        swap(q[i - 1], q[i]);
        int v1 = query(q);
        swap(q[0], q[i]);
        int v2 = query(q);
        swap(q[0], q[i]);
        ans[i] = (v2 - v1) / 2;
    }

    int mn = *min_element(ans.begin(), ans.end());
    for (int &a: ans) a += -mn + 1;
    answer(ans);
}