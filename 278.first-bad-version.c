/*
 * @lc app=leetcode id=278 lang=c
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
  long mid = 0;
  long l = 1;
  long r = n;
  long bad = 1;

  while (l <= r)
  {
    mid = (l + r) / 2;

    if (isBadVersion(mid))
    {
      bad = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  return bad;
}

// @lc code=end

