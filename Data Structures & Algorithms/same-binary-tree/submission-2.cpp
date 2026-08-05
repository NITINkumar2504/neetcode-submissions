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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while(!qu.empty()){
            auto [ftree, stree] = qu.front();
            qu.pop();

            if(ftree == NULL && stree == NULL) continue;
            if(ftree == NULL || stree == NULL) return false;
            if(ftree -> val != stree -> val) return false;

            qu.push({ ftree -> left, stree -> left });
            qu.push({ ftree -> right, stree -> right });
        }

        return true;
    }
};
