#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int count[26] = {0,};
    string input;
    cin >> input;
    for (char& c: input) {
        count[c - 'a']++;
    }

    for (int c: count) cout << c << ' ';
    cout << '\n';
}