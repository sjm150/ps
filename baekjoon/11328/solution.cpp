#include <iostream>

using namespace std;

bool is_possible(string& str1, string& str2) {
    if (str1.length() != str2.length()) return false;

    int count[26] = {};
    for (char& c: str1) count[c - 'a']++;
    for (char& c: str2) count[c - 'a']--;

    for (int c: count) {
        if (c != 0) return false;
    }

    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        string str1, str2;
        cin >> str1 >> str2;
        if (is_possible(str1, str2)) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}