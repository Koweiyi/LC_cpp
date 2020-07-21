/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.96%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 69.7K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {

        string  res;
        int preOrder = 0;

        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        while(index1 >= 0 || index2 >= 0){
            char c;
            if(index1 >= 0 && index2 >= 0)
                c = num1[index1] - '0' + num2[index2] + preOrder;
            else if(index1 >= 0)
                c = num1[index1] + preOrder;
            else 
                c = num2[index2] + preOrder;

            if(c > '9'){
                preOrder = 1;
                c -= 10;
            }else 
                preOrder = 0;
            res.push_back(c);
            index1 --;
            index2 --;
        }
        if(preOrder)
            res.push_back('1');
        
        reverse(res.begin(), res.end());
        return res;

    }
};
// @lc code=end

