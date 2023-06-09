#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        list<char> buffer;
        auto it = buffer.begin();
        string input;
        cin >> input;

        for (char i: input) {
            if (i == '<') {
                if (it != buffer.begin()) it--;
            } else if (i == '>') {
                if (it != buffer.end()) it++;
            } else if (i == '-') {
                if (it != buffer.begin()) it = buffer.erase(prev(it));
            } else {
                it = next(buffer.insert(it, i));
            }
        }

        for (char b: buffer) cout << b;
        cout << '\n';
    }
}