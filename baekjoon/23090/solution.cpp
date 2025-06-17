#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    priority_queue<int> mnq;
    priority_queue<int, vector<int>, greater<int>> mxq;
    ll mns = 0, mxs = 0, xsum = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        xsum += abs(x);
        if (mnq.empty() || mnq.top() >= y) {
            mnq.push(y);
            mns += y;
            if (mnq.size() > mxq.size() + 1) {
                int t = mnq.top();
                mnq.pop();
                mxq.push(t);
                mns -= t;
                mxs += t;
            }
        } else {
            mxq.push(y);
            mxs += y;
            if (mnq.size() < mxq.size()) {
                int t = mxq.top();
                mxq.pop();
                mnq.push(t);
                mxs -= t;
                mns += t;
            }
        }
        ll t = mnq.top();
        cout << t << ' ' << xsum + t * mnq.size() - mns + mxs - t * mxq.size() << '\n';
    }
}