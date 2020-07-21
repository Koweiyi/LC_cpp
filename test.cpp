#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {


        int l = 0, r = flowerbed.size() - 1;
        while(l < flowerbed.size() && flowerbed[l] == 0)
            l ++;
        if(l == flowerbed.size())
            return (l + 1) / 2 >= n;

        int res = 0;
        res += l / 2;

        while(r >= 0 && flowerbed[r] == 0)
            r --;

        res += (flowerbed.size() - 1 - r) / 2;

        while(l < r){
            while(l < flowerbed.size() && flowerbed[l] == 1)
                l ++;
            if(l >= r)
                break;
            int i = l;
            while(i < r && flowerbed[i] == 0)
                i ++;
            res += (i - l - 1) / 2;
            l = i;
        }
        return res >= n;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> f = {1, 0, 0, 0, 1};
    int n = 2;

    bool res = Solution().canPlaceFlowers(f, n);
    cout << res;


    
    return 0;
}
