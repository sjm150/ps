#include <string>
#include <vector>
#include <queue>

#define UP 8
#define DOWN 4
#define RIGHT 2
#define LEFT 1

using namespace std;

void set_up(vector<vector<int>>& edges, int x, int y) {
    edges[x][y] |= UP;
    edges[x][y + 1] |= DOWN;
}

void set_right(vector<vector<int>>& edges, int x, int y) {
    edges[x][y] |= RIGHT;
    edges[x + 1][y] |= LEFT;
}

vector<pair<int, int>> get_next(vector<vector<int>>& edges, int x, int y) {
    vector<pair<int, int>> ret;
    int val = edges[x][y];
    if (val & UP) ret.emplace_back(x, y + 1);
    if (val & DOWN) ret.emplace_back(x, y - 1);
    if (val & RIGHT) ret.emplace_back(x + 1, y);
    if (val & LEFT) ret.emplace_back(x - 1, y);
    
    return ret;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<bool>> up_covered(51, vector<bool>(51, false));
    vector<vector<bool>> right_covered(51, vector<bool>(51, false));
    for (auto& rec: rectangle) {
        for (int i = rec[0] + 1; i < rec[2]; i++) {
            for (int j = rec[1]; j < rec[3]; j++) {
                up_covered[i][j] = true;
            }
        }
        for (int i = rec[0]; i < rec[2]; i++) {
            for (int j = rec[1] + 1; j < rec[3]; j++) {
                right_covered[i][j] = true;
            }
        }
    }

    vector<vector<int>> edges(51, vector<int>(51, 0));
    for (auto& rec: rectangle) {
        int xmin = rec[0], ymin = rec[1], xmax = rec[2], ymax = rec[3];
        for (int i = xmin; i < xmax; i++) {
            if (!right_covered[i][ymin]) set_right(edges, i, ymin);
            if (!right_covered[i][ymax]) set_right(edges, i, ymax);
        }
        for (int j = ymin; j < ymax; j++) {
            if (!up_covered[xmin][j]) set_up(edges, xmin, j);
            if (!up_covered[xmax][j]) set_up(edges, xmax, j);
        }
    }
    
    vector<vector<int>> dist(51, vector<int>(51, -1));
    queue<pair<int, int>> q;
    dist[characterX][characterY] = 0;
    q.emplace(characterX, characterY);
    while (!q.empty()) {
        int xcurr = q.front().first, ycurr = q.front().second;
        int curr_dist = dist[xcurr][ycurr];
        q.pop();
        
        if (itemX == xcurr && itemY == ycurr) return curr_dist;
        
        for (auto& next: get_next(edges, xcurr, ycurr)) {
            int& next_dist = dist[next.first][next.second];
            if (next_dist < 0) {
                next_dist = curr_dist + 1;
                q.emplace(next.first, next.second);
            }
        }
    }
    
    return 0;
}