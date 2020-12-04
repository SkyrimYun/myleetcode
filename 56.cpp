#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ret;
        if (intervals.empty())
            return ret;
        sort(intervals.begin(), intervals.end());
        ret.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > ret[ret.size() - 1][1])
                ret.emplace_back(intervals[i]);
            else
                ret[ret.size() - 1][1] = max(intervals[i][1], ret[ret.size() - 1][1]);
        }
        return ret;

        // map<int, bool> vals;
        // vector<vector<int>> ret;
        // for (vector<int> interval : intervals)
        // {
        //     if (vals.count(interval[0]) > 0 && !vals[interval[0]])
        //         vals.erase(vals.find(interval[0]));
        //     else
        //         vals.emplace(interval[0], true);

        //     if (vals.count(interval[1]) > 0 && vals[interval[1]])
        //         vals.erase(vals.find(interval[1]));
        //     else
        //         vals.emplace(interval[1], false);
        // }
        // typedef map<int, bool>::iterator ite;
        // vector<int> interval;
        // int pass = 0;
        // for (ite it = vals.begin(); it != vals.end(); it++)
        // {
        //     if (pass == 0)
        //         interval.emplace_back(it->first);

        //     if (it->second)
        //         pass++;
        //     else
        //     {
        //         pass--;
        //         if (pass == 0)
        //         {
        //             interval.emplace_back(it->first);
        //             ret.emplace_back(interval);
        //             interval.clear();
        //         }
        //     }
        // }
        // return ret;

        // vector<int> first;
        // vector<int> end;
        // for (vector<int> interval : intervals)
        // {
        //     first.emplace_back(interval[0]);
        //     end.emplace_back(interval[1]);
        // }
        // sort(first.begin(), first.end());
        // sort(end.begin(), end.end());

        // vector<vector<int>> ret;
        // int i = 0, j = 0;
        // vector<int> interval;
        // interval.emplace_back(first[0]);
        // while (j != end.size() - 1)
        // {
        //     if (i == j)
        //         i++;
        //     if (first[i] > end[j])
        //     {
        //         interval.emplace_back(end[j]);
        //         ret.emplace_back(interval);
        //         interval.clear();
        //         interval.emplace_back(first[i]);
        //     }
        //     j++;
        //     if (j == end.size() - 1)
        //     {
        //         interval.emplace_back(end[j]);
        //         ret.emplace_back(interval);
        //     }
        // }
        // return ret;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 10}, {2, 6}, {8, 10}, {1, 7}};
    Solution s;
    vector<vector<int>> ret = s.merge(intervals);
    for (vector<int> interval : ret)
    {
        cout << interval[0] << ", " << interval[1] << endl;
    }
}