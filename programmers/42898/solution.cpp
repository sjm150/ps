#include <string>
#include <vector>

using namespace std;

int mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> n_path(m + 1, vector<int>(n + 1, 0));
    n_path[1][1] = 1;
    for (auto& puddle: puddles) n_path[puddle[0]][puddle[1]] = -1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (n_path[i][j] < 0) n_path[i][j] = 0;
            else n_path[i][j] += (n_path[i - 1][j] + n_path[i][j - 1]) % mod;
        }
    }
    
    return n_path[m][n];
}