/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.92%)
 * Likes:    2306
 * Dislikes: 0
 * Total Accepted:    159.6K
 * Total Submissions: 430K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
            return findMedianSortedArrays(nums2,nums1);
        
        int LMAX1,RMIN1,LMAX2,RMIN2,lo = 0,hi = 2 * n,c1,c2;
        while (lo <= hi )
        {
            c1 = (lo + hi) / 2;
            c2 = m + n - c1;
            LMAX1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMIN1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMAX2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMIN2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];
            if(LMAX1 > RMIN2)
                hi = c1 - 1;
            else if(LMAX2 > RMIN1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMAX1,LMAX2) + min(RMIN1,RMIN2)) / 2.0;
        
    }
};
// @lc code=end

