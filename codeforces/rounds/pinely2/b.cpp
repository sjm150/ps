#include <iostream>
using namespace std;

int idx[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            idx[p] = i;
        }
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (idx[i] > idx[i + 1]) cnt++;
        }
        cout << cnt << '\n';
    }
}