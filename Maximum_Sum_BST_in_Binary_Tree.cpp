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
    pair<int,pair<int,int>> solve(TreeNode* root , int &maxi){

        if(root == NULL){
            return {0 , {INT_MAX , INT_MIN}};
        }

        pair<int,pair<int,int>> lt;
        pair<int,pair<int,int>> rt;
        lt = solve(root->left, maxi);
        rt = solve(root->right, maxi);

       if(root->val > lt.second.second && root->val < rt.second.first){
           int sum = root->val + lt.first + rt.first;
           maxi = max(sum , maxi);
           int smallest = min(root->val , lt.second.first);
           int largest  = max(root->val , rt.second.second);
           return {sum , {smallest , largest}};
       }
       else{
           return {0 , {INT_MIN , INT_MAX}};
       }
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        solve(root , maxi);
        return maxi;
    }
};