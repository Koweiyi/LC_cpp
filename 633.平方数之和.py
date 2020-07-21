#
# @lc app=leetcode.cn id=633 lang=python
#
# [633] 平方数之和
#
# https://leetcode-cn.com/problems/sum-of-square-numbers/description/
#
# algorithms
# Easy (33.35%)
# Likes:    114
# Dislikes: 0
# Total Accepted:    21.9K
# Total Submissions: 65.8K
# Testcase Example:  '5'
#
# 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
# 
# 示例1:
# 
# 
# 输入: 5
# 输出: True
# 解释: 1 * 1 + 2 * 2 = 5
# 
# 
# 
# 
# 示例2:
# 
# 
# 输入: 3
# 输出: False
# 
# 
#
import math
# @lc code=start
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for i in range(int(math.sqrt(c / 2)) + 1):
            if math.sqrt(c - i * i) == int(math.sqrt(c - i * i)):
                return True
        
        return False
    
        
# @lc code=end

