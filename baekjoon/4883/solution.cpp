#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int graph[100000][3];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int k = 1; ; k++) {
        int n; cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        graph[0][0] = inf;
        graph[0][2] += graph[0][1];
        for (int i = 1; i < n; i++) {
            graph[i][0] += min(graph[i - 1][0], graph[i - 1][1]);
            graph[i][1] += min(min(graph[i][0], graph[i - 1][0]), min(graph[i - 1][1], graph[i - 1][2]));
            graph[i][2] += min(graph[i][1], min(graph[i - 1][1], graph[i - 1][2]));
        }
        cout << k << ". " << graph[n - 1][1] << '\n';
    }
}