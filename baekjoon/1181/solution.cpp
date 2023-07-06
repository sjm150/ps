#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, string> words[20000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words[i] = {word.length(), word};
    }
    sort(words, words + n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || words[i] != words[i - 1])
            cout << words[i].second << '\n';
    }
}