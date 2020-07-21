/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (49.45%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 58.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

private:
    bool is_aeiou(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c =='I' || c == 'O' || c =='U';
    }
public:
    string reverseVowels(string s) {

        int i = 0 , j = s.size() - 1;
        while(i < j){
            while(i < s.size() && !is_aeiou(s[i])) i ++;
            while(j >=0 && !is_aeiou(s[j])) j --;
            if(i < j) 
                swap(s[i ++], s[j --]);
        }

        return s;
    }
};
// @lc code=end

