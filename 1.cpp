/*
hashtable in c++ = unordered_map
key is unique
To add new element: better to use "insert" or "emplace" function; don't use "hash[key]=value", better to use this "[]" operation only for value checking
    "insert" and "emplace" will return a "pair<iterator,bool>" to show the position of the insertion and whether the insertion successes
    if the insertion key has already existed, the inerstion will fail and not update the original key-value pair
To see whether the table contains a key "hash.count(key)" if =0, not exist; =1, exist
To search a key: "hash.find(key)"
*/

//nmsl

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            pair<unordered_map<int, int>::iterator, bool> suc = hash.insert({nums[i], i});
            //cout << suc.second << endl;
            if (hash.count(target - nums[i]) > 0 && hash[target - nums[i]] != i)
            {
                return vector<int>{i, hash[target - nums[i]]};
            }
        }
        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> nums{3, 3};
    vector<int> ans = s.twoSum(nums, 6);
    for (int n : ans)
    {
        cout << n << endl;
    }
}
