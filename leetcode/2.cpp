struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode h;
        ListNode *cur = &h;
        int s = 0;
        while (l1 || l2 || s) {
            s += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur = cur->next = new ListNode(s % 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            s /= 10;
        }
        return h.next;
    }
};