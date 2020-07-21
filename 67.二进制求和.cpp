/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.69%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    85.8K
 * Total Submissions: 162.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.size() < b.size()){
            string c = b;
            b = a;
            a = c;
        }

        int index1 = a.size() - 1;
        int index2 = b.size() - 1;
        assert(index1 >= index2);
        
        while(index1 > 0){
            if(index2 >= 0 && b[index2] == '1')
                a[index1] ++;
            
            if(a[index1] == '3'){
                a[index1] = '1';
                a[index1 - 1] ++;
            }
            else if(a[index1] == '2'){
                a[index1] = '0';
                a[index1 - 1] ++;
            }
            index1 --;
            index2 --;
        }

        if(a.size() == b.size() && b[0] == '1'){
            a[0] ++;
        }

        if(a[0] == '3'){
            a[0] = '1';
            a = '1' + a;
        }
        if(a[0] == '2'){
            a[0] = '0';
            a = '1' + a;
        }

        return a;



    }
};
// @lc code=end

