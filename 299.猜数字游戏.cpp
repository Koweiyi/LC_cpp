/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 *
 * https://leetcode-cn.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Easy (47.99%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 28.6K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * 你正在和你的朋友玩 猜数字（Bulls and
 * Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”,
 * 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
 * 
 * 请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
 * 
 * 请注意秘密数字和朋友的猜测数都可能含有重复数字。
 * 
 * 示例 1:
 * 
 * 输入: secret = "1807", guess = "7810"
 * 
 * 输出: "1A3B"
 * 
 * 解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
 * 
 * 示例 2:
 * 
 * 输入: secret = "1123", guess = "0111"
 * 
 * 输出: "1A1B"
 * 
 * 解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
 * 
 * 说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {

        vector<int> record_s(10, 0);
        vector<int> record_g(10, 0);
        
        int n = min(secret.size(), guess.size());
        int Bull = 0;
        for(int i = 0; i < n ; i ++){
            if(secret[i] == guess[i])
                Bull ++;
            else{
                record_s[secret[i] - '0'] ++;
                record_g[guess[i] - '0']++;
            }
        }
        if(n == secret.size())
            for(int i =  n ; i < guess.size() ; i ++)
                record_g[guess[i] - '0'] ++;
        else 
            for(int i = n ; i < secret.size() ; i ++)
                record_s[secret[i] - '0'] ++;

        int Cow = 0;
        for(int i = 0 ; i < 10 ; i ++)
            Cow += min(record_g[i], record_s[i]);
        
        string res = to_string(Bull) + "A" + to_string(Cow) + "B";
        return res;
    }
};
// @lc code=end

