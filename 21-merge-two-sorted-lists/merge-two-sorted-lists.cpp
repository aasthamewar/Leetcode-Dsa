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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* temp1=new ListNode(-1);
        // ListNode* dummy=temp1;
        // while(list1 && list2){
        //     if(list1->val < list2->val){
        //         dummy->next=list1;
        //         list1=list1->next;
        //     }
        //     else{
        //     dummy->next=list2;
        //     list2=list2->next;
        //     }
        //     dummy=dummy->next;
        // }
        // if(list1)dummy->next=list1;
        // else{
        //     dummy->next=list2;
        // }
        // return dummy;


        //RECURSION
        if(!list1)return list2;
        if(!list2)return list1;
        if(list1->val < list2->val){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }


    }
};