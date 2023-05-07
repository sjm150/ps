#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    vector<vector<int>> max_money(2, vector<int>(n, 0));
    
    max_money[0][n - 1] = money[n - 1];
    max_money[0][n - 2] = max(money[n - 2], money[n - 1]);
    for (int i = n - 3; i >= 0; i--) {
        max_money[0][i] = max(max_money[0][i + 1], money[i] + max_money[0][i + 2]);
    }
    
    max_money[1][n - 2] = money[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        max_money[1][i] = max(max_money[1][i + 1], money[i] + max_money[1][i + 2]);
    }
    
    return max(max_money[0][1], max_money[1][0]);
}