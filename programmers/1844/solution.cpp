#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    q.emplace(0, 0);
    dist[0][0] = 1;
    while (!q.empty()) {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if (0 <= next_x && next_x < n &&
                0 <= next_y && next_y < m &&
                dist[next_x][next_y] < 0 && maps[next_x][next_y]) {
                q.emplace(next_x, next_y);
                dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            }
        }
    }
    
    return dist[n - 1][m - 1];
}