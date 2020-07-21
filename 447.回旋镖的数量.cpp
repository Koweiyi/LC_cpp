/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (57.56%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 21K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
 * 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [[0,0],[1,0],[2,0]]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0 ; i < points.size() ; i ++){
            unordered_map<int, int> record;
            for(int j = 0 ; j < points.size() ; j ++)
                if(j != i)
                    record[dis(points[i], points[j])] ++;
            
            for(pair<int, int> r : record)
                res += r.second * (r.second - 1);
        }
        return res;
    }   
private:
    int dis(const vector<int> & i, const vector<int> & j){
        assert(i.size() == 2 && j.size() == 2);
        return pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2);
    }
};
// @lc code=end

