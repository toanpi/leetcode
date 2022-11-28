/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reverse(struct ListNode* tail,struct ListNode** root)
{
  if (!tail || !root || !(*root))
  {
    return;
  }

  if (tail->next == NULL)
  {
    // Last one --> Swap with tail
    int temp = tail->val;
    tail->val = (*root)->val;
    (*root)->val = temp;

    *root = (*root)->next;

    return;
  }

  reverse(tail->next, root);

  if(root && tail)
  {
    int temp = tail->val;
    tail->val = (*root)->val;
    (*root)->val = temp;

    
    if(((*root) == tail) || ((*root)->next == tail))
    {
      *root = NULL;
    }
    else
    {
      *root = (*root)->next;
    }
  }
}

struct ListNode* reverseList(struct ListNode* head)
{
  if (!head)
  {
    return head;
  }

  reverse(head, &head);

  return head;
}
// @lc code=end

