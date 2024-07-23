#include <bits/stdc++.h>
using namespace std;

typedef struct Bitree {
    vector<int> val;
    Bitree(int n): val(n + 1, 0) {}
    void add(int i) {
        i++;
        while (i < val.size()) {
            val[i]++;
            i += i & -i;
        }
    }
    int get(int i) {
        i++;
        int ret = 0;
        while (i) {
            ret += val[i];
            i &= i - 1;
        }
        return ret;
    }
} bit_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ai(n);
    for (int i = 0; i < n; i++) {
        cin >> ai[i].first;
        ai[i].second = i;
    }
    sort(ai.begin(), ai.end());
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[ai[i].second] = i;
    
    bit_t bit(n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 - bit.get(ord[i]) << '\n';
        bit.add(ord[i]);
    }
}