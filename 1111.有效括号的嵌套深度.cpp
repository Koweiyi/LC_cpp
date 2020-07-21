/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 *
 * https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/
 *
 * algorithms
 * Medium (67.69%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 8.2K
 * Testcase Example:  '"(()())"'
 *
 * 有效括号字符串 定义：对于每个左括号，都能找到与之对应的右括号，反之亦然。详情参见题末「有效括号字符串」部分。
 * 
 * 嵌套深度 depth 定义：即有效括号字符串嵌套的层数。详情参见题末「嵌套深度」部分。
 * 
 * 
 * 
 * 给你一个「有效括号字符串」 seq，请你将其分成两个不相交的子序列 A 和 B，且 A 和 B 都满足有效括号字符串的定义（注意：A.length +
 * B.length = seq.length）。
 * 
 * 由于可能存在多种划分方案，请你从中选出 任意 一组有效括号字符串 A 和 B，使 max(depth(A), depth(B)) 的可能取值最小。其中
 * depth(A) 表示 A 的嵌套深度，depth(B) 表示 B 的嵌套深度。
 * 
 * 请你返回一个长度为 seq.length 的答案数组 answer，编码规则如下：如果 seq[i] 是 A 的一部分，那么 answer[i] =
 * 0。否则，answer[i] = 1。即便有多个满足要求的答案存在，你也只需返回 一个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：seq = "(()())"
 * 输出：[0,1,1,1,1,0]
 * 
 * 
 * 示例 2：
 * 
 * 输入：seq = "()(())()"
 * 输出：[0,0,0,1,1,0,1,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.size <= 10000
 * 
 * 
 * 
 * 
 * 有效括号字符串：
 * 
 * 仅由 "(" 和 ")" 构成的字符串，对于每个左括号，都能找到与之对应的右括号，反之亦然。
 * 
 * 下述几种情况同样属于有效括号字符串：
 * 
 * 
 * 空字符串
 * 连接，可以记作 AB（A 与 B 连接），其中 A 和 B 都是有效括号字符串
 * 嵌套，可以记作 (A)，其中 A 是有效括号字符串
 * 
 * 
 * 嵌套深度：
 * 
 * 类似地，我们可以定义任意有效括号字符串 s 的 嵌套深度 depth(S)：
 * 
 * 
 * s 为空时，depth("") = 0
 * s 为 A 与 B 连接时，depth(A + B) = max(depth(A), depth(B))，其中 A 和 B 都是有效括号字符串
 * s 为嵌套情况，depth("(" + A + ")") = 1 + depth(A)，其中 A 是有效括号字符串
 * 
 * 
 * 例如：""，"()()"，和 "()(()())" 都是有效括号字符串，嵌套深度分别为 0，1，2，而 ")(" 和 "(()" 都不是有效括号字符串。
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);

        int deep = 0;
        for(int i = 0 ; i < seq.size() ; i ++ )
        {
            if(seq[i] == '('){
                res[i] = deep ++ % 2;
            }
            else {
                res[i] = -- deep % 2;
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string test = "(()())";
    vector<int> res = Solution().maxDepthAfterSplit(test);
    return 0;
}
