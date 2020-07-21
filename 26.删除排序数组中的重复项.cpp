/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include <bits/stdc++.h>
using namespace std;









// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// int main(int argc, char const *argv[])
// {
//     return 0;
// }

// @lc code=start

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size()<=1)
        {
            return nums.size();   
        }
        int j = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i]!=nums[j])
                nums[++j]=nums[i];
        }
        return j+1;
    }
};
// @lc code=end
