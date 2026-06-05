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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(prev->next && prev->next->next){
            ListNode* slow=prev->next;
            ListNode* fast=slow->next;
            // slow=1, fast=2
            // main swapping condition
            slow->next=fast->next; // 1->3->4
            fast->next=slow; // slow=1
            prev->next=fast; // becuase dummy still pointing to 1

            prev = slow;

        }
        return dummy->next;

    }
};