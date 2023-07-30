#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while (true) {
        string n; cin >> n;
        if (n == "0") break;
        bool ispal = true;
        for (int i = 0; i < (n.length() + 1) / 2; i++) {
            if (n[i] != n[n.length() - 1 - i]) {
                ispal = false;
                break;
            }
        }
        if (ispal) cout << "yes\n";
        else cout << "no\n";
    }
}