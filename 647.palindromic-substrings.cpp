/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool isPalindromic(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if (l <= r)
        {
            if (dp[l][r] != -1)
            {
                return dp[l][r];
            }

            dp[l][r] = (s[l] == s[r]);

            if (dp[l][r] && r - l > 2)
            {
                dp[l][r] = isPalindromic(s, l + 1, r - 1, dp);
            }

            return dp[l][r];
        }

        return false;
    }

    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                cnt += isPalindromic(s, i, j, dp);
            }
        }

        return cnt;
    }
};
// @lc code=end
