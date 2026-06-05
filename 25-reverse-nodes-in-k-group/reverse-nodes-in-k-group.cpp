class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        int groups = len / k;

        ListNode* curr = head;
        ListNode* prevGroupTail = NULL;
        ListNode* newHead = NULL;

        for(int g = 0; g < groups; g++){

            ListNode* groupHead = curr;
            ListNode* prev = NULL;

            // Reverse k nodes
            for(int i = 0; i < k; i++){
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // First reversed group gives new head
            if(newHead == NULL)
                newHead = prev;

            // Connect previous group
            if(prevGroupTail)
                prevGroupTail->next = prev;

            // Current group's original head
            // becomes tail after reversal
            prevGroupTail = groupHead;
        }

        // Connect leftover nodes
        prevGroupTail->next = curr;

        return newHead;
    }
};