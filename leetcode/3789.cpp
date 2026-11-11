typedef long long ll;

class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth < cost1 + cost2) {
            int b = min(need1, need2);
            return ll(costBoth) * b + min(cost1, costBoth) * ll(need1 - b) + min(cost2, costBoth) * ll(need2 - b);
        } else {
            return ll(cost1) * need1 + ll(cost2) * need2;
        }
    }
};