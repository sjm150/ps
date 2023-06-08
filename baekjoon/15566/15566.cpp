#include <iostream>

using namespace std;

int N, M;

int interest[15][4];
int prefer[15][2];
int edge[15][15];

int placed[15];

bool process(int num);

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> interest[i][0] >> interest[i][1] >> interest[i][2] >> interest[i][3];
    }
    for (int i = 0; i < N; i++) {
        cin >> prefer[i][0] >> prefer[i][1];
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        cin >> edge[x - 1][y - 1];
        edge[y - 1][x - 1] = edge[x - 1][y - 1];
    }

    if (process(0)) {
        cout << "YES" << endl;
        for (int i = 0; i < N - 1; i++) {
            cout << placed[i] << " ";
        }
        cout << placed[N - 1] << endl;
    } else {
        cout << "NO" << endl;
    }
}

bool process(int num) {
    if (num == N) return true;

    for (int pref = 0; pref < 2; pref++) {
        if (pref == 1 && prefer[num][0] == prefer[num][1]) break;

        int vertex = prefer[num][pref] - 1;
        if (placed[vertex] == 0) {
            bool able = true;

            for (int other_v = 0; other_v < N; other_v++) {
                int subject = edge[vertex][other_v] - 1;
                int other_frog = placed[other_v] - 1;
                if (other_frog >= 0 && subject >= 0 && interest[num][subject] != interest[other_frog][subject]) {
                    able = false;
                }
            }

            if (able) {
                placed[vertex] = num + 1;
                if (process(num + 1)) return true;
                placed[vertex] = 0;
            }
        }
    }

    return false;
}