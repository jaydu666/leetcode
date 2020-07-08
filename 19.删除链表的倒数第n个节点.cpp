/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode guard(0);
        guard.next = head;
        ListNode *fast = head, *slow = head, *slow_last = &guard;
        for (int i = 0; i < n-1; ++i)
            fast = fast->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
            slow_last = slow_last->next;
        }
        slow_last->next = slow_last->next->next;
        return guard.next;
    }
};

// int main(void)
// {
//     vector<int> v = {1,2,3,4,5};
//     ListNode guard(0);
//     ListNode *p = &guard;
//     for (int i = 0; i < v.size(); ++i)
//     {
//         p->next = new ListNode(v[i]);
//         p = p->next;
//     }
//     Solution::removeNthFromEnd(guard.next, 2);

//     return 0;
// }

// @lc code=end

