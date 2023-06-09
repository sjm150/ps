#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string str1, str2;
    cin >> str1 >> str2;

    int count[26] = {};
    for (char& c: str1) count[c - 'a']++;
    for (char& c: str2) count[c - 'a']--;

    int remove = 0;
    for (int c: count) remove += abs(c);

    cout << remove << '\n';
}