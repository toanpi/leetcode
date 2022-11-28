/*
 * @lc app=leetcode id=744 lang=c
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start


char nextGreatestLetter(char* letters, int lettersSize, char target)
{
  int lo = 0;
  int hi = lettersSize - 1;

  while (lo <= hi)
  {
    int mi = lo + (hi - lo) / 2;
  
    if (letters[mi] <= target)
    {
      lo = mi + 1;
    }
    else
    {
      hi = mi - 1;
    }
  }

  return letters[lo % lettersSize];
}

// @lc code=end

