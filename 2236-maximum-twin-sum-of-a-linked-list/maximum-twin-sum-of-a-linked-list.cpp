
class Solution {
public:
    int pairSum(ListNode* head) {
        int len=0;
        ListNode* middle=head;
        while(middle){
            middle = middle->next;
            len++;
        }
        middle = head;
        for(int i=0;i<len/2;i++){
            middle = middle->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = middle;
        ListNode* nextnode = NULL;
        while(curr){
            nextnode = curr->next;
            curr->next = prev;
            //moving pointer ahead
            prev = curr;
            curr = nextnode;
        }
        
        ListNode* first = head;
        ListNode* second = prev;

        int maxisum=0;
        while(second){
            int sum = first->val + second->val;
            maxisum = max(maxisum,sum);
            first = first->next;
            second = second->next;
        }
        return maxisum;
        

    }
};