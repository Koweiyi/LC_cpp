/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 *
 * https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (60.47%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 22.7K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释:
 * 5的二进制数是: 101
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 7
 * 输出: False
 * 解释:
 * 7的二进制数是: 111
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 11
 * 输出: False
 * 解释:
 * 11的二进制数是: 1011
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: 10
 * 输出: True
 * 解释:
 * 10的二进制数是: 1010
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {

        if(n < 3)
            return true;
        int c = n % 2;
        n /= 2;
        while(n){
            if(n % 2 == c)
                return false;
            else {
                c = n % 2;
                n /= 2;
            }
        }
        return true;
    }
};
// @lc code=end

