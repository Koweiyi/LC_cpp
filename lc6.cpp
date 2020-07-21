#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;

        vector<vector<char>> resV(numRows, vector<char>());
        for(int i = 0 ; i < s.size() ; i ++ )
        {
            int mod = i % ((numRows - 1) * 2);
            resV[mod < numRows ? mod : 2 * (numRows - 1) - mod].push_back(s[i]);
        }

        string res = "";
        for(int i = 0 ; i < numRows ; i ++ )
            for(char  c : resV[i])
                res += c;
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "LEETCODEISHIRING";
    int numRows = 3;
    string res = Solution().convert(s, numRows);
    cout << res;
    return 0;
}
