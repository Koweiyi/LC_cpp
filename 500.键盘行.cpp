/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (69.03%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 24.7K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    vector<int> alpha = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};

public:
    vector<string> findWords(vector<string>& words) {

        vector<string> res;
        for(int i = 0 ; i < words.size() ; i ++){
            vector<int> record(3, 0);
            for(int j = 0 ; j < words[i].size() ; j ++)
                record[alpha[tolower(words[i][j]) - 'a']] ++;
            int cnt = 0;
            for(int j = 0 ; j < 3 ; j ++)
                if(record[j])
                    cnt ++;
            
            if(cnt < 2)
                res.push_back(words[i]);

        }
        return res;

    }
};
// @lc code=end

