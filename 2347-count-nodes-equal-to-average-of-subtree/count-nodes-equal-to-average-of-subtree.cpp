/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    tuple<int,int> fun(TreeNode* root,int &count){
        if(!root)
        return {0,0};
        int sum=0;
        int size=0;
        auto [lsum,lcount]=fun(root->left,count);
        auto [rsum,rcount]=fun(root->right,count);
        sum+=root->val+lsum+rsum;
        size=1+lcount+rcount;
        if(sum/size==root->val)
        count++;
        return {sum,size};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        fun(root,count);
        return count;
    }
};