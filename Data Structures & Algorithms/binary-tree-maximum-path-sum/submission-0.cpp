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
    int check(TreeNode* root, int sum, int &maxsum) {
        if (root == NULL) return 0;

        int leftsum = 0, rightsum = 0;

        if (root->left) {
            leftsum = check(root->left, sum, maxsum);   
        }
        if (root->right) {
            rightsum = check(root->right, sum, maxsum); 
        }

  
        leftsum = max(0, leftsum);
        rightsum = max(0, rightsum);

        
        int through = root->val + leftsum + rightsum;
        maxsum = max(maxsum, through);

       
        sum = root->val + max(leftsum, rightsum);
        return sum;
    }

    int maxPathSum(TreeNode* root) {
        int sum = 0;
        int maxsum = INT_MIN;
        check(root, sum, maxsum);
        return maxsum;
    }
};

