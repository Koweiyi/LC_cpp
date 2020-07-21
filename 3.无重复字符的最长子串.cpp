/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        // int alpha[256] = {0};
        // int l = 0, r = -1;
        // int res = 0;
        // while (l < s.size())
        // {
        //     if (r + 1 < s.size() && alpha[s[r + 1]] == 0)
        //         alpha[s[++r]]++;
        //     else
        //         alpha[s[l++]]--;

        //     res = max(res , r - l + 1);
        // }
        // return res;

        vector<int> alpha(256, 0);
        int l = 0, r = 0;
        int res = 0;
        while(l < s.size())
        {
            if(r < s.size() && alpha[s[r]] == 0)
                alpha[s[r ++]] ++;
            else 
                alpha[s[l ++]] --;
            
            res = max(res, r - l);
        }

        return res;

    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    int res = Solution().lengthOfLongestSubstring("abcabcbb");
    cout << res;
    return 0;
}
