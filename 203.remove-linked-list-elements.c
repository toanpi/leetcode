/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *removeElements(struct ListNode *head, int val)
{
  struct ListNode *pre = NULL;
  struct ListNode *cur = head;

  while (cur)
  {
    if (cur->val == val)
    {
      if(pre)
      {
        pre->next = cur->next;
      }
      else
      {
        head = cur->next;
      }
    }
    else
    {
      pre = cur;
    }

    cur = cur->next;
  }

  return head;
}

// @lc code=end

