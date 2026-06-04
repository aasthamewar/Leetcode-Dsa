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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=head;
        int len=0;
        while(dummy){
            len++;
            dummy=dummy->next; // in this dummy has reached the end (null)
        }
        //if head needs to be remove
        if(len==n){
            return head->next;
        }
        int pos=len-n;
        dummy=head;
        for(int i=1;i<pos;i++){
            dummy=dummy->next;
        }
        dummy->next=dummy->next->next;
        return head;

    }
};