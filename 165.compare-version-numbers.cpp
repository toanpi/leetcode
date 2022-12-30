/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int n1 = version1.size();
        int n2 = version2.size();

        for (int i = 0, j = 0; i < n1 || j < n2;)
        {
            string rev1 = "";
            string rev2 = "";

            while (i < n1 && version1[i] != '.')
            {
                rev1 += version1[i++];
            }

            while (j < n2 && version2[j] != '.')
            {
                rev2 += version2[j++];
            }

            int k1 = rev1.size() ? stoi(rev1) : 0;
            int k2 = rev2.size() ? stoi(rev2) : 0;

            if (k1 != k2)
            {
                return k1 > k2 ? 1 : -1;
            }

            ++i;
            ++j;
        }

        return 0;
    }
};
// @lc code=end
