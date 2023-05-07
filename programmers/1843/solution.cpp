#include <vector>
#include <string>

using namespace std;

int inf = 2000000;

int solution(vector<string> arr) {
    int n = (arr.size() + 1) /2;
    vector<bool> is_minus(n - 1);
    vector<int> numbers(n);
    for (int i = 0; i < n - 1; i++) is_minus[i] = (arr[i * 2 + 1] == "-");
    for (int i = 0; i < n; i++) numbers[i] = stoi(arr[i * 2]);
    
    vector<vector<int>> max_cache(n, vector<int>(n, -inf));
    vector<vector<int>> min_cache(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) max_cache[i][i] = min_cache[i][i] = numbers[i];
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                if (is_minus[k]) {
                    max_cache[i][j] = max(max_cache[i][j], max_cache[i][k] - min_cache[k + 1][j]);
                    min_cache[i][j] = min(min_cache[i][j], min_cache[i][k] - max_cache[k + 1][j]);
                } else {
                    max_cache[i][j] = max(max_cache[i][j], max_cache[i][k] + max_cache[k + 1][j]);
                    min_cache[i][j] = min(min_cache[i][j], min_cache[i][k] + min_cache[k + 1][j]);
                }
            }
        }
    }
    
    return max_cache[0][n - 1];
}