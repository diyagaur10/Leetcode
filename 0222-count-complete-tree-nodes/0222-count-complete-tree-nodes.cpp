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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if(lh == rh) return (1<<lh ) - 1; //2 ki power h/lh - 1 (formula)to find nodes
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findHeightLeft(TreeNode* node){
        int hgt= 0;
        while(node){
            hgt++;
            node = node->left;
        }
        return hgt;
    }
    int findHeightRight(TreeNode* node){
        int hgt= 0;
        while(node){
            hgt++;
            node = node->right;
        }
        return hgt;
    }
};