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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if(!head || !head->next) {
            return head;
        }

        ListNode *current = head;
        
        while(current->next)
        {
            int currentVal = current->val;
            int nextVal = current->next->val;

            int commonDivisor = gcd(currentVal, nextVal);

            ListNode *newNode = new ListNode(commonDivisor);
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        }
        return head;
    }
};