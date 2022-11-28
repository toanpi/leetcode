/*
 * @lc app=leetcode id=401 lang=c
 *
 * [401] Binary Watch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void permute(int *num, int l, int r, int k,
             int *buf, int *bufLen,
             char **ret, int *retLen)
{
  if ((l > r) || (k > (r - l + 1)))
  {
    return;
  }

  for (int i = l; i <= r; i++)
  {
    buf[(*bufLen)++] = num[i];

    if (k == 1)
    {
      int hour = 0;
      int minute = 0;

      for (int d = 0; d < (*bufLen); d++)
      {
        if (buf[d] > 5)
        {
          hour += 1 << (buf[d] - 6);
        }
        else
        {
          minute += 1 << buf[d];
        }
      }

      if (hour < 12 && minute < 60)
      {
        ret[*retLen] = malloc(6 * sizeof(char));
        sprintf(ret[(*retLen)++], "%d:%02d", hour, minute);
      }
    }
    else
    {
      permute(num, i + 1, r, k - 1, buf, bufLen, ret, retLen);
    }

    (*bufLen)--; // Backtrack
  }
}

char **readBinaryWatch(int turnedOn, int *returnSize)
{
  char **ret = calloc(60 * 12, sizeof(char *));
  int len = 0;
  int pos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int buf[10] = {0};
  int buf_len = 0;

  if (turnedOn > 0)
  {
    permute(pos, 0, 9, turnedOn, buf, &buf_len, ret, &len);
  }
  else
  {
    ret[len++] = "0:00";
  }

  *returnSize = len;
  return ret;
}

// @lc code=end

