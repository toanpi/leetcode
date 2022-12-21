/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    string sum(string num1, string num2)
    {
        string res = "";
        int s1 = 0;
        int s2 = 0;
        int n = 0;

        while (n || s1 < num1.size() || s2 < num2.size())
        {
            n += s1 < num1.size() ? num1[s1++] - '0' : 0;
            n += s2 < num2.size() ? num2[s2++] - '0' : 0;
            res += (n % 10) + '0';
            n /= 10;
        }

        return res;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        string ret = "";
        int m10 = 0;
        unordered_map<int, string> db;

        ret.reserve(300);

        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int k = num1[i] - '0';

            if (db.find(k) == db.end())
            {
                int s2 = num2.size();
                int n = 0;

                db[k].reserve(s2 + 200);

                while (s2 || n)
                {
                    n += k * (s2 ? num2[--s2] - '0' : 0);
                    db[k] += (n % 10) + '0';
                    n /= 10;
                }
            }

            ret = sum(string(m10, '0') + db[k], ret);
            ++m10;
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
// @lc code=end
