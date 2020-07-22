/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        
        while(index < bits.size() - 1)
            index += bits[index] ? 2 : 1;

        return index == bits.size() - 1;
    }
};
// @lc code=end

