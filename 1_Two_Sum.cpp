#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        /*sort(nums.begin(), nums.end());

        cout << "Sorted: ";
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;*/
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
                for (int j = i + 1; j < len; j++)
                {
                    if(nums[i] + nums[j] == target)
                    {
                        result.push_back(i);
                        result.push_back(j);

                        return result;
                    }

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