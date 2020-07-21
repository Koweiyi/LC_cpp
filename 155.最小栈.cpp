/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (52.21%)
 * Likes:    416
 * Dislikes: 0
 * Total Accepted:    86.1K
 * Total Submissions: 164.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
public:
    vector<int> S;
    int min = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        S.push_back(x);
        min = std::min(min, x);
    }
    
    void pop() {
        int b = S.back();
        if(b == min)
        {
            min = INT_MAX;
            for(int i = 0 ; i < S.size() - 1 ; i ++ )
                min = std::min(min, S[i]);
        }
        S.pop_back();
    }
    
    int top() {
        return S.back();
    }
    
    int getMin() {
        assert(S.size() > 0);
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

