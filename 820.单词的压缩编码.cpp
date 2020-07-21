/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (41.19%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 58.9K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 * 
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes =
 * [0, 2, 5]。
 * 
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 * 
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> record(words.begin(), words.end());
        for(string word : words)
            for(int i = 1 ; i < word.size() ; i ++ )
                record.erase(word.substr(i));
        
        int res = 0;
        for(string word : record)
            res += word.size() + 1;
        
        return res;
    }
};
// @lc code=end
