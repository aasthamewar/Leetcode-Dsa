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
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        stack<ListNode*>st;
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            st.push(curr);
            curr=curr->next;
            cnt++;
        }

        //reorder
        curr = head;
        for(int i=0;i<cnt/2;i++){
            ListNode* last = st.top();
            st.pop();

            ListNode* nextnode = curr->next;
            curr->next = last;
            last->next = nextnode;

            curr = nextnode;
        }

        curr->next = nullptr;
    }
};