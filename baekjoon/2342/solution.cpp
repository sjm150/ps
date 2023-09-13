#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int input[100001];
int str[100001][5];

int cost(int from, int to) {
    if (from == 0) return 2;
    else if (from == to) return 1;
    else if ((from - to) % 2 == 0) return 4;
    else return 3;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n = 0;
    while (true) {
        cin >> input[n];
        if (input[n] == 0) break;
        fill(str[n], str[n] + 5, inf);
        n++;
    }
    str[0][0] = 2;
    for (int i = 0; i < n - 1; i++) {
        for (int o = 0; o < 5; o++) {
            str[i + 1][o] = min(str[i + 1][o], str[i][o] + cost(input[i], input[i + 1]));
            str[i + 1][input[i]] = min(str[i + 1][input[i]], str[i][o] + cost(o, input[i + 1]));
        }
    }
    int mins = inf;
    for (int o = 0; o < 5; o++) mins = min(mins, str[n - 1][o]);
    cout << mins << '\n';
}