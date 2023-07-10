#include <iostream>

using namespace std;

int len[1001][1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) len[i][j] = max(len[i][j], len[i - 1][j - 1] + 1);
        }
    }
    cout << len[s1.length()][s2.length()] << '\n';
}