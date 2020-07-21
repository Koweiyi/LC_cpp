#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {   
        int n = nums.size();
        vector<int> dp(n, -1);

        int res = INT_MAX;
        for(int len = 1 ; len <= n ; len ++ )
            for(int i = nums.size() - len ; i >= 0 ; i -- )
            {
                int j = len + i - 1;
                dp[j] = (len == 1 ? nums[i] : dp[j - 1] + nums[j]);
                if(dp[j] >= s)
                    return len;
            }

        return res == INT_MAX ? 0 : res;
    };
};

int main(int argc, char const *argv[])
{
    int s = 11;
    vector<int> nums = {1,2,3,4,5};
    int res = Solution().minSubArrayLen(s, nums);
    cout << res;
    return 0;
}
