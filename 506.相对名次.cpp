/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (54.15%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 17.1K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
struct peo
{
    int num;
    int index;
    bool operator < (const peo x) const{
        return num < x.num;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<peo> P(nums.size(),peo());
        for(int i = 0 ; i < nums.size() ; i ++){
            P[i].num = nums[i];
            P[i].index = i;
        }
        sort(P.begin(), P.end());
        reverse(P.begin(), P.end());
        vector<string> res(nums.size(), "");
        for(int i = 0 ; i < P.size() ; i ++){
            if(i == 0)
                res[P[i].index] = "Gold Medal";
            else if(i == 1)
                res[P[i].index] = "Silver Medal";
            else if(i == 2)
                res[P[i].index] = "Bronze Medal";
            else 
                res[P[i].index] = to_string(i + 1);
        }
        return res;
    }
};
// @lc code=end

