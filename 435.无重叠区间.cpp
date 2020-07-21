/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (44.99%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 24.2K
 * Testcase Example:  '[[1,2]]'
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 * 
 * 注意:
 * 
 * 
 * 可以认为区间的终点总是大于它的起点。
 * 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [ [1,2], [2,3], [3,4], [1,3] ]
 * 
 * 输出: 1
 * 
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [ [1,2], [1,2], [1,2] ]
 * 
 * 输出: 2
 * 
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [ [1,2], [2,3] ]
 * 
 * 输出: 0
 * 
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &a,const Interval &b ){
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b. end;
}

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {

        if(intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> dp = vector<int>(intervals.size(), 1);
        for(int i = 1 ; i < intervals.size() ; i ++ )
            for(int j = 0 ; j < i ; j ++ )
                if(intervals[j].end <= intervals[i].start)
                    dp[i] = max(dp[i], 1 + dp[j]);

        return dp.back();
    }
};
// @lc code=end

