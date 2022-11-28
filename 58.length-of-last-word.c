/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char *s)
{
  if (!s)
  {
    return 0;
  }

  int s_len = strlen(s);
  int len = 0;

  for (int i = s_len - 1; i >= 0; i--)
  {
    if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
    {
      len++;
    }

    if ((s[i] == ' ') && (len > 0))
    {
      break;
    }
  }

  return len;
}

// @lc code=end

