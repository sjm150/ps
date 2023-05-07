#include <string>
#include <vector>

using namespace std;

void get_tree_size(int n, int root, vector<vector<int>>& edges, vector<int>& tree_size) {
    int& size = tree_size[root];
    size = 1;
    for (int next: edges[root]) {
        if (tree_size[next]) continue;
        get_tree_size(n, next, edges, tree_size);
        size += tree_size[next];
    }
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> edges(n);
    for (auto& wire: wires) {
        int v1 = wire[0] - 1, v2 = wire[1] - 1;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    
    vector<int> tree_size(n, 0);
    get_tree_size(n, 0, edges, tree_size);
    
    int mindiff = n;
    for (int size: tree_size) {
        int currdiff = abs(n - 2 * size);
        if (mindiff > currdiff) mindiff = currdiff;
    }
    return mindiff;
}