/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxL = 0;
        int cnt = 0;
        deque<int> zero;

        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                cnt++;
            }
            else
            {
                if (k > 0)
                {
                    cnt++;
                    k--;
                    zero.push_back(i);
                }
                else
                {
                    if (zero.size())
                    {
                        cnt = i - zero.front();
                        zero.pop_front();
                        zero.push_back(i);
                    }
                    else
                    {
                        cnt = 0;
                    }
                }
            }

            maxL = max(maxL, cnt);
        }

        return maxL;
    }
};
// @lc code=end
