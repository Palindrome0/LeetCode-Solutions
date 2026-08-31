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
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* fu=head->next;
        vector<int>vec;
        int count=1;
        while(curr!=NULL&&fu!=NULL){
            if(prev!=NULL&&fu!=NULL){
                if(curr->val>fu->val&&curr->val>prev->val)
                vec.push_back(count);
                else if(curr->val<fu->val&&curr->val<prev->val)
                vec.push_back(count);
            }
            count++;
            prev=curr;
            curr=fu;
            fu=fu->next;
        }
        if(vec.size()<=1)
        return {-1,-1};
        int maxi=*max_element(vec.begin(),vec.end());
        int mini=*min_element(vec.begin(),vec.end());
        int diff=INT_MAX;
        for(int i=1;i<vec.size();i++){
            diff=min(diff,vec[i]-vec[i-1]);
        }
        return {diff,maxi-mini};
    }
};