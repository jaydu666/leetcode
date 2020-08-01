/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

// struct NodeStack {
//     TreeNode *node;
//     bool has_left;
//     NodeStack(TreeNode *node): node(node), has_left(false){}
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<NodeStack> st;
//         st.push(NodeStack(root));
//         while (!st.empty())
//         {
//             NodeStack &top = st.top();
//             if (top.node == NULL)
//             {
//                 st.pop();
//                 continue;
//             }
//             if (!top.has_left)
//             {
//                 st.push(NodeStack(top.node->left));
//                 top.has_left = true;
//                 continue;
//             }
//             res.push_back(top.node->val);
//             NodeStack right_node(top.node->right);
//             st.pop();
//             st.push(right_node);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> st;
//         TreeNode *curr = root;
//         while (curr != NULL || !st.empty())
//         {
//             while (curr != NULL)
//             {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             curr = st.top();
//             st.pop();
//             res.push_back(curr->val);
//             curr = curr->right;
//         }
//         return res;
//     }
// };

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                res.push_back(curr->val);
                curr = curr->right;
                continue;
            }
            TreeNode* pre = curr->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }
            pre->right = curr;
            TreeNode *tmp = curr->left;
            curr->left = NULL;
            curr = tmp;
        }
        return res;
    }
};

// @lc code=end

