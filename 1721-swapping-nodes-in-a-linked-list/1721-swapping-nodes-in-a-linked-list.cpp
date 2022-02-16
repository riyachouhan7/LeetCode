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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) {
            return head;
        }
        int val = k;
        ListNode* temp1 = head;
        while(k>1) {
            temp1 = temp1->next;
            k--;
        }
        ListNode*temp2 = head;
        int count = 1;
        while(temp2) {
            temp2 = temp2->next;
            count++;
        }
        ListNode*temp3 = head;
        int end = count - val;
        while(end>1 and temp3->next) {
            temp3 = temp3->next;
            end--;
        }
        swap(temp1->val, temp3->val);
        return head;
    }
};