#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int pre; cin >> pre;
        n--;
        int maxa = 0;
        while (n--) {
            int cur; cin >> cur;
            if (pre > cur) maxa = max(maxa, pre);
            pre = cur;
        }
        cout << maxa << '\n';
    }
}