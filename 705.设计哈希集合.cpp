/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start

struct Node{
    int key;
    Node * next;
    Node(int key): key(key), next(nullptr){};
};
int len = 1000;

class MyHashSet {
public:

    vector<Node*> arr;

    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<Node*>(len, new Node(-1));
    }
    
    void add(int key) {

        int temp = key % len;
        Node *node = arr[temp];
        Node *pre;

        while(node){
            if(node->key == key)
                return;
            pre = node;
            node = node->next;
        } 
        Node *newNode = new Node(key);
        pre->next = newNode;

    }
    
    void remove(int key) {

        int temp = key % len;
        Node * node = arr[temp];

        while(node->next){
            if(node->next->key == key){
                node->next = node->next->next;
                return;
            }
            node = node->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int temp = key % len;
        Node *node = arr[temp];
        
        while(node->next){
            if(node->next->key == key)
                return true;
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

