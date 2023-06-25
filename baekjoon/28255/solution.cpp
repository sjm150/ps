#include <iostream>

using namespace std;

string rev_of(string& str) {
    string ret = "";
    for (int i = str.length() - 1; i >= 0; i--) ret += str[i];
    return ret;
}

string tail_of(string& str) {
    return str.substr(1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;
    while (max_case--) {
        string line;
        cin >> line;
        int l = (line.length() + 2) / 3;

        string sub = line.substr(0, l);
        string rev = rev_of(sub);
        string tail = tail_of(sub);
        string tail_rev = tail_of(rev);

        if (line == sub + rev + sub ||
            line == sub + tail_rev + sub ||
            line == sub + rev + tail ||
            line == sub + tail_rev + tail) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}