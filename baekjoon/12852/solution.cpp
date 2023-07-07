#include <iostream>

using namespace std;

int n;
int dist[1000001];
int track[1000001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dist[i] = dist[i - 1] + 1;
        track[i] = i - 1;
        if (i % 3 == 0) {
            int d = dist[i / 3] + 1;
            if (dist[i] > d) {
                dist[i] = d;
                track[i] = i / 3;
            }
        }
        if (i % 2 == 0) {
            int d = dist[i / 2] + 1;
            if (dist[i] > d) {
                dist[i] = d;
                track[i] = i / 2;
            }
        }
    }
    cout << dist[n] << '\n';
    for (int i = n; i != 1; i = track[i]) cout << i << ' ';
    cout << "1\n";
}