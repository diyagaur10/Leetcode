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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        dfs(root1,ans1);
        dfs(root2,ans2);
        return ans1 == ans2;
        
    }
    void dfs(TreeNode* node, vector<int>&ans){
        if(node == NULL){
            return ;
        }
        if(node->left== NULL  && node->right == NULL ){
            ans.push_back(node->val);
        }
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
};