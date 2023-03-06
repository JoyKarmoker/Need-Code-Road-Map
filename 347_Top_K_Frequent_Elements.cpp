#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<int> ans;
        map<int, int> mp;

        for (auto num : nums)
        {
            mp[num]++;
        }

        vector<pair<int, int>> temp;

        for (auto m : mp)
        {
            temp.push_back({m.first, m.second});
        }

        sort(temp.begin(), temp.end(), cmp);

        for(int i=0; i<k; i++)
        {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans;
    ans = sol.topKFrequent(nums, k);

    cout << "Answer: ";
    for (auto a:ans)
    {
        cout << a << " ";
    }

    return 0;
}