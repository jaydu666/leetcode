/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev, *next;
    Node(){}
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node> node_map;
    int cap;
    int size;
    Node head;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head.next = head.prev = &head;
    }
    
    int get(int key) {
        auto it = node_map.find(key);
        if (it == node_map.end())
            return -1;
        move_head(it->second);
        return it->second.value;
    }
    
    void move_head(Node &node)
    {
        del(node);
        insert_head(node);
    }

    void insert_head(Node &node)
    {
        node.next = head.next;
        node.prev = &head;
        head.next->prev = &node;
        head.next = &node;
    }

    void del(Node &node)
    {
        if (&node == &head)
            return;
        node.next->prev = node.prev;
        node.prev->next = node.next;
    }

    Node *del_tail()
    {
        if (head.prev == &head)
            return NULL;
        Node *node = head.prev;
        del(*node);
        return node;
    }

    void put(int key, int value) {
        auto it = node_map.find(key);
        if (it != node_map.end())
        {
            it->second.value = value;
            move_head(it->second);
            return;
        }
        if (size >= cap)
        {
            Node *node = del_tail();
            if (node != NULL)
            {
                node_map.erase(node->key);
                size -= 1;
            }
        }
        if (size < cap)
        {
            node_map[key] = Node(key, value);
            insert_head(node_map[key]);
            size += 1;
        }
    }
};

// int main(void)
// {
//     LRUCache lruCache(2);
//     lruCache.put(1, 1);
//     lruCache.put(2, 2);
//     lruCache.get(1);
//     lruCache.put(3, 3);
//     lruCache.get(2);
//     lruCache.put(4, 4);
//     lruCache.get(1);
//     lruCache.get(3);
//     lruCache.get(4);
// }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

