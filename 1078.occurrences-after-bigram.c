/*
 * @lc app=leetcode id=1078 lang=c
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **findOcurrences(char *text, char *first, char *second, int *returnSize)
{
  char **ret = malloc(5 * sizeof(char *));
  int size = 0;
  bool firstMatched = false;
  bool secondMatched = false;

  char *s = strtok(text, " ");

  while (s)
  {
    if (secondMatched) ret[size++] = s;
    
    secondMatched = firstMatched && !strcmp(second, s);
    firstMatched = !strcmp(first, s);

    s = strtok(NULL, " ");
  }

  *returnSize = size;
  return ret;
}

// @lc code=end

