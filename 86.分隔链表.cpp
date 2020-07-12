/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_guard, greater_guard;
        ListNode *pless = &less_guard, *pgreater = &greater_guard;
        while (head)
        {
            ListNode **p = NULL;
            if (head->val < x) p = &pless;
            else p = &pgreater;
            (*p)->next = head;
            head = head->next;
            *p = (*p)->next;
            (*p)->next = NULL;
        }
        if (&greater_guard != pgreater)
        {
            pless->next = greater_guard.next;
        }
        return less_guard.next;
    }
};
// @lc code=end

