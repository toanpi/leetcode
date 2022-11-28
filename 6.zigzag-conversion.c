/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 */

// @lc code=start


char * convert(char * s, int numRows)
{
  if (numRows <= 1)
  {
    return s;
  }

  int s_len = strlen(s);
  int indexs[numRows];
  char res[1000] = {0};
  int row = 0;
  int add = 1;

  memset(indexs, 0, sizeof(indexs));

  for (int i = 0; i < s_len; i++)
  {
    if (row >= numRows - 1)
    {
      add = -1;
    }
    if (row <= 0)
    {
      add = 1;
    }
    
    indexs[row]++;
    row += add;
  }

  // Calculate row index
  int cur_idx = 0;
  for (int i = 0; i < numRows; i++)
  {
    // 0: 10 - 1: 20 - 2: 10
    int num = indexs[i];
    indexs[i] = cur_idx;
    cur_idx += num;
  }

  // Fill to new string
  row = 0;
  for (int i = 0; i < s_len; i++)
  {
    if (row >= numRows - 1)
    {
      add = -1;
    }
    if (row <= 0)
    {
      add = 1;
    }
    
    res[indexs[row]] = s[i];
    
    indexs[row]++;
    row += add;
  }

  memcpy(s, res, s_len);

  return s;
}


// @lc code=end

