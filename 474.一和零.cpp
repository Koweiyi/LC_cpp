/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode-cn.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (51.18%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 13.1K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 在计算机界中，我们总是追求用有限的资源获取最大的收益。
 * 
 * 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
 * 
 * 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 * 
 * 注意:
 * 
 * 
 * 给定 0 和 1 的数量都不会超过 100。
 * 给定字符串数组的长度不会超过 600。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * 输出: 4
 * 
 * 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: Array = {"10", "0", "1"}, m = 1, n = 1
 * 输出: 2
 * 
 * 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:

    vector<vector<vector<int>>> memo;

    pair<int,int> check(string str){
        int first = 0, second = 0;
        for(char c : str){
            if(c == '0')
                first ++;
            else 
                second ++;
        }
        return make_pair(first, second);
    } 
    int tryFindMAXFrom(const vector<string>& strs, int m, int n, int index){
        
        if(index == strs.size() || m < 0 || n < 0 )
            return 0;

        if(memo[m][n][index] != -1)
            return memo[m][n][index];
        
        pair<int,int> p = check(strs[index]);
        int res = tryFindMAXFrom(strs, m, n, index + 1);
        if(m - p.first >=0 && n - p.second >= 0)
            res = max(res, 1 + tryFindMAXFrom(strs, m - p.first, n - p.second, index + 1));

        memo[m][n][index] = res;
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 0)
            return 0;

        memo = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size(), -1)));
        
        return tryFindMAXFrom(strs, m, n, 0);

    }   
};
// @lc code=end

