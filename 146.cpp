/*
哈希表查找快，但是无固定顺序
链表增删快，但是查找慢
此题需要查找快，增删也快
所以结合哈希和链表，把哈希表映射key到链表iterator（位置）
链表在stl中直接调list容器
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

class LRUCache
{
private:
    int sz;
    unordered_map<int, list<pair<int, int>>::iterator> ht;
    list<pair<int, int>> order;

public:
    LRUCache(int capacity) : sz(capacity){};

    int get(int key)
    {
        if (ht.count(key) > 0)
        {
            auto node = *ht[key];
            order.erase(ht[key]);
            order.push_front(node);
            ht[key] = order.begin();
            return node.second;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        auto node = make_pair(key, value);

        if (ht.count(key) == 1)
        {
            order.erase(ht[key]);
        }
        else
        {
            if (ht.size() == sz)
            {
                ht.erase(order.back().first);
                order.pop_back();
            }
        }

        order.push_front(node);
        ht[key] = order.begin();
    }
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
}