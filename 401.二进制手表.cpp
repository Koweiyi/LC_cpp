/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (51.87%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 27.9K
 * Testcase Example:  '0'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
 * 
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 * 
 * 
 * 
 * 例如，上面的二进制手表读取 “3:25”。
 * 
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 * 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<string>> hours = {
        {"0:"},
        {"1:", "2:", "4:", "8:"},
        {"3:", "5:", "6:", "9:", "10:"},
        {"7:", "11:"}
    };
    vector<vector<string>> minite = {
        {"00"},
        {"01", "02", "04", "08", "16", "32"},
        {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},
        {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37","38", "41", "42", "44", "49", "50", "52", "56"},
        {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},
        {"31", "47", "55", "59"}
    };

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i = 0 ; i < 4 && i <= num ; i ++){
            for(int j = 0 ; j < hours[i].size() ; j ++){
                string h = hours[i][j];
                for(int k = 0 ; (num - i) < 6 && k < minite[num - i].size() ; k ++)
                    res.push_back(h + minite[num - i][k]);
            }
        }

        return res;
    }
};
// @lc code=end

