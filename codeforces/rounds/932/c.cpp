#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        vector<pi> ba(n);
        for (int i = 0; i < n; i++) cin >> ba[i].second >> ba[i].first;
        sort(ba.begin(), ba.end());

        int len = 0;
        for (int i = 0; i < n; i++) {
            priority_queue<int> pq;
            ll sum = ba[i].second;
            if (sum <= l && 1 > len) len = 1;

            for (int j = i + 1; j < n; j++) {
                sum += ba[j].second + ba[j].first - ba[j - 1].first;
                pq.emplace(ba[j].second);
                while (!pq.empty() && sum > l) {
                    sum -= pq.top();
                    pq.pop();
                }
                if (sum <= l && pq.size() + 1 > len) len = pq.size() + 1;
            }
        }

        cout << len << '\n';
    }
}