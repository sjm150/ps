#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> wins(n, vector<bool>(n, false));
    for (auto& r: results) {
        int v1 = r[0] - 1, v2 = r[1] - 1;
        wins[v1][v2] = true;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                wins[i][j] = wins[i][j] | (wins[i][k] & wins[k][j]);
            }
        }
    }
    
    int accurate = 0;
    for (int i = 0; i < n; i++) {
        int det = 0;
        for (int j = 0; j < n; j++) {
            det += wins[i][j] | wins[j][i];
        }
        
        if (det == n - 1) accurate++;
    }
    return accurate;
}
