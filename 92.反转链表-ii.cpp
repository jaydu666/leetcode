/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode guard(0);
        guard.next = head;
        ListNode *before=NULL, *first=&guard;
        for (int i = 0; i < m; ++i)
        {
            before = first;
            first = first->next;
        }
        ListNode *now = first->next;
        for (int i = m; i < n; ++i)
        {
            ListNode *tmp = now->next;
            now->next = before->next;
            before->next = now;
            now = tmp;
        }
        first->next = now;
        return guard.next;
    }
};

// int main(void)
// {
//     vector<int> v = {1,2, 3, 4, 5};
//     ListNode guard(0), *p = &guard;
//     for (auto it = v.begin(); it != v.end(); ++it)
//     {
//         p->next = new ListNode(*it);
//         p = p->next;
//     }
//     Solution s;
//     s.reverseBetween(guard.next, 2, 4);

//     return 0;
// }

// @lc code=end

