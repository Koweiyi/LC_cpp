/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {

        string res = str;

        for(auto &c : res){
            c = tolower(c);
        }
        return res;
    }
};
// @lc code=end

