/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
  struct ListNode *root = NULL;
  struct ListNode *pre = NULL;

  while (list1 || list2)
  {
    // If list is null
    int val = 0;

    if (list1 && ((!list2) || (list1->val < list2->val)))
    {
      val = list1->val;
      list1 = list1->next;
    }
    else
    {
      val = list2->val;
      list2 = list2->next;
    }

    struct ListNode *new = malloc(sizeof(struct ListNode));

    if (!new)
    {
      break;
    }

    new->val = val;
    new->next = NULL;

    if (pre)
    {
      pre->next = new;
    }
    else
    {
      root = new; // First one
    }

    pre = new;
  }

  return root;
}

// @lc code=end

