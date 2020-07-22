/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> res;

    bool isSelfDividingNumber(int num){
        int n = num;
        while(n){
            if(n % 10 == 0 || num % (n % 10))
                return false;
            n /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {

        for(int i = left ; i <= right ; i ++)
            if(isSelfDividingNumber(i))
                res.push_back(i);

        return res;
    }
};
// @lc code=end

