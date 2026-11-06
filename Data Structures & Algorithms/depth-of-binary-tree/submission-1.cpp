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

/* 

ALGO

Base Case (Rukne ki condition):

Agar current node (root) NULL (yaani empty) hai, toh iska matlab iski koi height nahi hai. Is case mein 0 return kar do.

Left Subtree ki Height nikalo:

Recursion ka use karke current node ke left child (root->left) ki max depth calculate karo aur use leftHeight variable mein store kar lo.

Right Subtree ki Height nikalo:

Same tarike se, current node ke right child (root->right) ki max depth calculate karo aur use rightHeight variable mein store kar lo.

Max Height calculate karke return karo:

leftHeight aur rightHeight mein se jo bhi value badi ho, use choose karo.

Kyunki hum current node ko bhi count kar rahe hain, isliye us max height mein 1 add karke return kar do: 1 + max(leftHeight, rightHeight).
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight, rightHeight);

    }
};
