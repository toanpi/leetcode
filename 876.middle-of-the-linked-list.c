/*
 * @lc app=leetcode id=876 lang=c
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
  if (!head)
  {
    return head;
  }

  struct ListNode *mid = NULL;
  struct ListNode *fast = head;
  struct ListNode *slow = head;

  while (fast)
  {
    fast = fast->next;

    if (!fast)
    {
      break;
    }

    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

// @lc code=end

