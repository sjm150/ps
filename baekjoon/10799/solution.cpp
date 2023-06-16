#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int stacked = 0;
    int pieces = 0;
    bool prev = false;
    string ps;
    cin >> ps;
    for (char c: ps) {
        if (c == '(') {
            stacked++;
            prev = true;
        } else {
            stacked--;
            if (prev) pieces += stacked;
            else pieces++;
            prev = false;
        }
    }

    cout << pieces << '\n';
}