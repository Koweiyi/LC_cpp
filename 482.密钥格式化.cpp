/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 *
 * https://leetcode-cn.com/problems/license-key-formatting/description/
 *
 * algorithms
 * Easy (39.10%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 22.1K
 * Testcase Example:  '"5F3Z-2e-9-w"\n4'
 *
 * 有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。
 * 
 * 给你一个数字 K，请你重新格式化字符串，除了第一个分组以外，每个分组要包含 K 个字符；而第一个分组中，至少要包含 1 个字符。两个分组之间需要用
 * '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。
 * 
 * 给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "5F3Z-2e-9-w", K = 4
 * 输出："5F3Z-2E9W"
 * 解释：字符串 S 被分成了两个部分，每部分 4 个字符；
 * 注意，两个额外的破折号需要删掉。
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "2-5g-3-J", K = 2
 * 输出："2-5G-3J"
 * 解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * S 的长度可能很长，请按需分配大小。K 为正整数。
 * S 只包含字母数字（a-z，A-Z，0-9）以及破折号'-'
 * S 非空
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {

        string res = "";
        if(S.size() <= K){
            for(int i = 0 ; i < S.size() ; i ++)
                if(S[i] != '-')
                    res.push_back(toupper(S[i]));
            return res;
        }
        
        int index = S.size() - 1;
        int len = 0;
        while(index >= 0){
            if(S[index] != '-'){
                res.push_back(toupper(S[index]));
                len ++;
                if(len && len % K == 0)
                    res.push_back('-');
            }
            index --;
        }    
        if(res.back() == '-')
            res.pop_back();
        
        reverse(res.begin(), res.end());
        return res;


    }
};
// @lc code=end

