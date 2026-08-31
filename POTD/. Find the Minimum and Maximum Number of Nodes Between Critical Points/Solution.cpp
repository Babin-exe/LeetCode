// Problem Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode *prev = head, *curr = head->next, *next = curr->next;
        vector<int> ans = {-1, -1};

        int first = -1;
        int previous = -1;
        int last = -1;
        int idx = 1;
        int minGap =INT_MAX;

        while (next != nullptr) {

            bool critical = false;
            int pval = prev->val;
            int cval = curr->val;
            int nval = next->val;

            if ((cval > pval && cval > nval) || (cval < pval && cval < nval)) {
                critical = true;
            }

            if (critical) {

                if (first == -1) {
                    first = idx;
                } else {
                    minGap = min(minGap, idx - previous);
                }
                previous = idx;
                last = idx;
            }
            prev = curr;
            curr = next;
            next = next->next;

            idx++;
        }

        if (first == -1 || first == last) return {-1, -1};

        return {minGap, last-first};
    }
};
