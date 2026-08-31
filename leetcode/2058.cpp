struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pre = head->val, fst = 0, lst = 0, cur = 1, mn = 1e6;
        head = head->next;
        for (; head->next; pre = head->val, cur++, head = head->next) {
            if ((pre <= head->val && head->val <= head->next->val) || (head->next->val <= head->val && head->val <= pre)) continue;
            if (!fst) fst = cur;
            if (lst) mn = min(mn, cur - lst);
            lst = cur;
        }
        return {mn < 1e6 ? mn : -1, fst < lst ? lst - fst : -1};
    }
};