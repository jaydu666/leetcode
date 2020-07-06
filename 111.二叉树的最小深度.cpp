/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

struct QueueElem {
    TreeNode *node;
    int depth;
    QueueElem(TreeNode *node, int depth)
    {
        this->node = node;
        this->depth = depth;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<QueueElem> queue;
        queue.push(QueueElem(root, 1));
        while (!queue.empty())
        {
            TreeNode *node = queue.front().node;
            int depth = queue.front().depth;
            queue.pop();
            if (node->left == NULL && node->right == NULL)
            {
                return depth;
            }
            if (node->left != NULL) queue.push(QueueElem(node->left, depth+1));
            if (node->right != NULL) queue.push(QueueElem(node->right, depth+1));
        }
        return 0;
    }
};
// @lc code=end

