/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start

class Trie{
private:
    bool is_string;
    Trie *next[26];
public:
    Trie(){
        is_string=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word){
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    
    bool search(string word){
        Trie *root=this;
        for(const auto& w:word){
            // 当节点值存在时，判断该节点是否表示为一个字符串，不是的话，直接返回false,否则续循环;当节点值不存在时直接返回false
            if(root->next[w-'a']==nullptr||root->next[w-'a']->is_string==false)
                return false;
            root=root->next[w-'a'];
        }
        return true;
    }
};

class Solution {
public:  
    string longestWord(vector<string>& words) {
        
        if(words.size() == 0)
            return "";
        Trie * root = new Trie();

        for(const auto& word : words)
            root->insert(word);

        string res = "";

        for(const auto& word : words){
            if(root->search(word)){
                if(word.size() > res.size())
                    res = word;
                else if(word.size() == res.size() && word<res)
                    res = word;
            }
        }

        return res;
        
    }
};
// @lc code=end

