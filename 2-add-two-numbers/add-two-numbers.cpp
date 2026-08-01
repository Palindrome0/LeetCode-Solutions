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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(ptr1&&ptr2){
            sum=ptr1->val+ptr2->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1){
            sum=ptr1->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;
            ptr1=ptr1->next;
        }
        while(ptr2){
            sum=ptr2->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;
            ptr2=ptr2->next;
        }
        if(carry!=0){
            dummy->next=new ListNode(carry);
            dummy=dummy->next;
        }
        return head->next;
    }
};