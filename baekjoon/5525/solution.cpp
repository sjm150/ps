#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    bool valid = true;
    bool sw = false;
    int k = -1, cnt = 0;
    while (m--) {
        char c; cin >> c;
        if (valid) {
            if (sw) {
                if (c == 'I') k = 0;
                else sw = false;
            } else {
                if (c == 'I') {
                    k++;
                    if (k >= n) cnt++;
                    sw = true;
                } else {
                    valid = false;
                }
            }
        } else {
            if (c == 'I') {
                valid = true;
                sw = true;
                k = 0;
            }
        }
    }
    cout << cnt << '\n';
}