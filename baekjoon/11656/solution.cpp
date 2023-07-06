#include <iostream>
#include <algorithm>

using namespace std;

string suffix[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string word;
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        suffix[i] = word.substr(i);
    }
    sort(suffix, suffix + word.length());
    for (int i = 0; i < word.length(); i++) cout << suffix[i] << '\n';
}