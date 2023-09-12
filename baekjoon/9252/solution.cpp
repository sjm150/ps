#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

string s1, s2;
int len[1001][1001];
pi lst[1001][1001];

void print_back(int i, int j) {
    if (i == 0 || j == 0) return;
    auto [pi, pj] = lst[i - 1][j - 1];
    print_back(pi, pj);
    cout << s1[i - 1];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (len[i - 1][j] > len[i][j - 1]) {
                len[i][j] = len[i - 1][j];
                lst[i][j] = lst[i - 1][j];
            } else {
                len[i][j] = len[i][j - 1];
                lst[i][j] = lst[i][j - 1];
            }
            if (s1[i - 1] == s2[j - 1] && len[i][j] < len[i - 1][j - 1] + 1) {
                len[i][j] = len[i - 1][j - 1] + 1;
                lst[i][j] = {i, j};
            }
        }
    }
    cout << len[n][m] << '\n';
    print_back(lst[n][m].first, lst[n][m].second);
    cout << '\n';
}