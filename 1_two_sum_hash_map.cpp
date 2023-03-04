#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> mp;
        mp.insert({nums[0], 0});
        int len = nums.size();
        int diff;
        for (int i = 1; i < len - 1; i++)
        {
            diff = target - nums[i];
            if(mp.count(diff))
            {
                result.push_back(mp[diff]);
                result.push_back(i);
                return result;
            }

            else
            {
                mp.insert({nums[i], i});
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "[";
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << "]";
    return 0;
}