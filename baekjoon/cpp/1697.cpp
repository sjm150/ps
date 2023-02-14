#include <iostream>
#include <queue>

using namespace std;

int N, K;
int times[100001];

queue<int> q;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    cin >> N >> K;

    if (N < K) {
        q.push(N);
        while (q.size() > 0) {
            int x = q.front();

            if (x != 0 && x < K) {
                int next_x = x * 2;
                if (next_x < 100001 && times[next_x] == 0) {
                    times[next_x] = times[x] + 1;
                    if (next_x == K) break;
                    q.push(next_x);
                }
            }
            if (x < K) {
                int next_x = x + 1;
                if (times[next_x] == 0) {
                    times[next_x] = times[x] + 1;
                    if (next_x == K) break;
                    q.push(next_x);
                }
            }
            if (x > 0) {
                int next_x = x - 1;
                if (times[next_x] == 0) {
                    times[next_x] = times[x] + 1;
                    if (next_x == K) break;
                    q.push(next_x);
                }
            }

            q.pop();
        }

        cout << times[K] << endl;
    } else {
        cout << N - K << endl;
    }
}