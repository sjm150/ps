#include <iostream>
#include <vector>

#define INF 100

using namespace std;

int n, k, m, l;
vector<int> prereqs;
vector<int> open_courses;
int semester_cache[10][1 << 12];

void init_cache() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            semester_cache[i][j] = -1;
        }
    }
}

int req_semesters(int semester, int taken);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n >> k >> m >> l;
        prereqs = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            for (int j = 0; j < r; j++) {
                int pre;
                cin >> pre;
                prereqs[i] |= (1 << pre);
            }
        }
        open_courses = vector<int>(m, 0);
        for (int i = 0; i < m; i++) {
            int r;
            cin >> r;
            for (int j = 0; j < r; j++) {
                int crs;
                cin >> crs;
                open_courses[i] |= (1 << crs);
            }
        }
        init_cache();

        int result = req_semesters(0, 0);
        if (result == INF) cout << "IMPOSSIBLE" << endl;
        else cout << result << endl;
    }
}

int bit_count(int bits) {
    int count = 0;
    while (bits != 0) {
        count += (bits & 1);
        bits = bits / 2;
    }
    return count;
}

int req_semesters(int semester, int taken) {
    if (bit_count(taken) >= k) return 0;
    if (semester >= m) return INF;

    int& cache = semester_cache[semester][taken];
    if (cache >= 0) return cache;
    cache = INF;

    int courses = (open_courses[semester] & ~taken);
    for (int i = 0; i < n; i++) {
        if ((courses & (1 << i)) && ((prereqs[i] & taken) != prereqs[i])) {
            courses &= ~(1 << i);
        }
    }

    for (int take = courses; take; take = ((take - 1) & courses)) {
        if (bit_count(take) > l) continue;
        cache = min(cache, req_semesters(semester + 1, taken | take) + 1);
    }
    cache = min(cache, req_semesters(semester + 1, taken));

    return cache;
}