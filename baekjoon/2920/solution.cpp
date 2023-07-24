#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    bool asc = true, dsc = true;
    int prev; cin >> prev;
    for (int i = 1; i < 8; i++) {
        int curr; cin >> curr;
        if (prev < curr) dsc = false;
        else asc = false;
        prev = curr;
    }
    if (asc) cout << "ascending\n";
    else if (dsc) cout << "descending\n";
    else cout << "mixed\n";
}