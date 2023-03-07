#include <iostream>

using namespace std;

int n, max_route;
int walls[100][3];
int heights[100];
bool tree_edges[100][100];

int get_height_and_calculate_max_route(int root_idx);
int insert_tree_node(int lhs_idx, int rhs_idx);
bool is_lhs_in_rhs(int x1, int y1, int r1, int x2, int y2, int r2);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        cin >> walls[0][0] >> walls[0][1] >> walls[0][2];
        for (int j = 0; j < n; j++) {
            tree_edges[0][j] = false;
        }
        for (int i = 1; i < n; i++) {
            cin >> walls[i][0] >> walls[i][1] >> walls[i][2];
            for (int j = 0; j < n; j++) {
                tree_edges[i][j] = false;
            }

            if (insert_tree_node(i, 0) == -1) tree_edges[0][i] = true;
        }

        max_route = 0;
        get_height_and_calculate_max_route(0);
        cout << max(heights[0], max_route) << endl;
    }
}

int get_height_and_calculate_max_route(int root_idx) {
    int& height = heights[root_idx];
    height = 0;

    int first = 0, second = 0;
    int child_count = 0;
    for (int i = 0; i < n; i++) {
        if (tree_edges[root_idx][i]) {
            child_count++;
            height = max(height, get_height_and_calculate_max_route(i) + 1);

            if (heights[i] > first) {
                second = first;
                first = heights[i];
            } else if (heights[i] > second) {
                second = heights[i];
            }
        }
    }

    if (child_count >= 2) {
        max_route = max(max_route, first + second + 2);
    }

    return height;
}

// -1: not found, 0: insertion finished, 1: found insertable place
int insert_tree_node(int new_node_idx, int curr_idx) {
    auto& new_node = walls[new_node_idx];
    auto& curr = walls[curr_idx];
    if (new_node[2] > curr[2]) {
        if (is_lhs_in_rhs(curr[0], curr[1], curr[2], new_node[0], new_node[1], new_node[2])) {
            return 1;
        } else {
            return -1;
        }
    }
    if (!is_lhs_in_rhs(new_node[0], new_node[1], new_node[2], curr[0], curr[1], curr[2])) {
        return -1;
    }

    for (int i = 1; i < n; i++) {
        if (tree_edges[curr_idx][i]) {
            int result = insert_tree_node(new_node_idx, i);
            if (result == 1) {
                tree_edges[curr_idx][i] = false;
                tree_edges[curr_idx][new_node_idx] = true;
                tree_edges[new_node_idx][i] = true;
                return 0;
            } else if (result == 0) {
                return 0;
            }
        }
    }

    tree_edges[curr_idx][new_node_idx] = true;
    return 0;
}

bool is_lhs_in_rhs(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dr = r2 - r1;
    return dx * dx + dy * dy < dr * dr;
}