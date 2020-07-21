#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {

private:
    vector<vector<int>> res;

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 2 ; ){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] + nums[i] > 0)
                    do{right --;} while(right > 0 && nums[right + 1] == nums[right]);
                else if(nums[left] + nums[right] + nums[i] < 0)
                    do{left ++;} while(left < nums.size() && nums[left - 1] == nums[left] );
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    do{right --;} while(right > 0 && nums[right + 1] == nums[right]);
                    do{left ++;} while(left < nums.size() && nums[left - 1] == nums[left] );
                }
            }

            do{i++;} while ( i < nums.size() && nums[i - 1] == nums[i]);    
        }
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> test = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution().threeSum(test);
    for(auto v : res){
        for(auto num : v)
            cout << num <<" ";
        cout << endl;
    }
        
    return 0;
}
