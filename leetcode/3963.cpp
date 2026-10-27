class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        fill(grid[0].begin(), grid[0].end(), '.');
        for (auto &s: grid) s.back() = '.';
        return grid;
    }
};