#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int stacked = 0;
        string ps;
        cin >> ps;

        bool invalid = false;
        for (char c: ps) {
            if (c == '(') {
                stacked++;
            } else {
                stacked--;
                if (stacked < 0) {
                    invalid = true;
                    break;
                }
            }
        }

        if (!invalid && stacked == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}