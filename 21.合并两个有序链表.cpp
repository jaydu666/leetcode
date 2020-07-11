/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode *p = &head;
        while (l1 != NULL || l2 != NULL)
        {
            ListNode** now = NULL;
            if (l1 != NULL && l2 != NULL)
            {
                now = (l1->val < l2->val)? &l1: &l2;
            }
            else
            {
                now = (l1 != NULL)? &l1: &l2;
            }
            p->next = *now;
            p = p->next;
            *now = (*now)->next;
        }
        p->next = NULL;
        return head.next;
    }
};
// @lc code=end

