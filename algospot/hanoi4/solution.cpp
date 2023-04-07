#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int move_num(int start, int end, int n);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n, start = 0;
        cin >> n;
        for (int i = 0; i < 4; i++) {
            int r;
            cin >> r;
            for (int j = 0; j < r; j++) {
                int plate;
                cin >> plate;
                start |= (i << ((plate - 1) * 2));
            }
        }

        cout << move_num(start, (1 << n * 2) - 1, n) << endl;
    }
}


int move_num(int start, int end, int n) {
    if (start == end) return 0;

    vector<int> num(1 << (n * 2), 0);
    queue<int> q;

    num[start] = 1;
    num[end] = -1;
    q.push(start);
    q.push(end);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int top[4] = {-1, -1, -1, -1};
        for (int plate = n - 1; plate >= 0; plate--) {
            int pos = ((curr >> (plate * 2)) & 3);
            top[pos] = plate;
        }
        for (int i = 0; i < 4; i++) {
            if (top[i] == -1) continue;
            for (int j = 0; j < 4; j++) {
                if (i == j || ((top[j] != -1) && top[i] > top[j])) continue;
                
                int next = ((curr & ~(3 << (top[i] * 2))) | (j << (top[i] * 2)));
                if (num[next] == 0) {
                    num[next] = num[curr] > 0 ? num[curr] + 1 : num[curr] - 1;
                    q.push(next);
                } else if ((num[next] < 0 && num[curr] > 0) || (num[next] > 0 && num[curr] < 0)) {
                    return abs(num[next]) + abs(num[curr]) - 1;
                }
            }
        }
    }

    return -1;
}