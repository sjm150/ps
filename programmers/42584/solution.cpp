#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer;
    stack<pair <int, int>> st; // price, index pair
    
    for (int i = 0; i < n; i++) answer.push_back(n - 1 - i);
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first > prices[i]) {
            int idx = st.top().second;
            answer[idx] = i - idx;
            st.pop();
        }
        st.emplace(prices[i], i);
    }
    
    return answer;
}