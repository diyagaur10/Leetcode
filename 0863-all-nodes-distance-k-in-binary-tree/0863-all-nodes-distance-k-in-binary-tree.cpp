/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    // Step 1: Build parent map
    void buildParentMap(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParentMap(root, nullptr);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                vector<TreeNode*> neighbors = { curr->left, curr->right, parent[curr] };

                for (TreeNode* nbr : neighbors) {
                    if (nbr && !visited.count(nbr)) {
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            dist++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};